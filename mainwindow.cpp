#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // First, widgets are disabled untill you import files
    ui->processBox->setEnabled(false);

    // Set up of buttons that expand widgets
    ui->widgetNotebook->hide();
    ui->widgetPlotSettings->hide();

    ui->notebookButton->setAutoDefault(false);
    ui->notebookButton->setCheckable(true);
    ui->plotstngsButton->setAutoDefault(false);
    ui->plotstngsButton->setCheckable(true);

    // Set up the Notebook object
    notebook.setTextEdit(ui->notebookTextEdit);
    QCPDocumentObject *plotObjectHandler = new QCPDocumentObject(this);
    ui->notebookTextEdit->document()->documentLayout()->registerHandler(QCPDocumentObject::PlotTextFormat, plotObjectHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief setState Records input values from text (spin) boxes.
 * Takes all the user-defined values from the application window and stores them via the System class members.
 */
void MainWindow::setState(){

    system->setParam("samplingFreq", (ui->editSamplingFreq->text()).toInt());
    system->setParam("flatWindowed", ui->isWindowedCheck->isChecked());
    system->setParam("flatOrder", (ui->flatOrderEdit->text()).toInt());

    if (ui->unitsFlatWin->currentText() == "Seconds"){
        int chosenWin = (ui->flatWinEdit->text()).toInt();
        int totalWin = system->getParam("samplingFreq") * chosenWin;
        system->setParam("flatWin", totalWin);
    }
    else system->setParam("flatWin", (ui->flatWinEdit->text()).toInt());

    if (ui->unitsFiltWin->currentText() == "Seconds"){
        int chosenWin = (ui->editMovAvgWin->text()).toInt();
        int totalWin = system->getParam("samplingFreq") * chosenWin;
        system->setParam("filtWin", totalWin);
    }
    else system->setParam("filtWin", (ui->editMovAvgWin->text()).toInt());

    if (ui->unitsVarWin->currentText() == "Seconds"){
        int chosenWin = (ui->varWinEdit->text()).toInt();
        int totalWin = system->getParam("samplingFreq") * chosenWin;
        system->setParam("varWin", totalWin);
    }
    else system->setParam("varWin", (ui->varWinEdit->text()).toInt());

    if (ui->unitsVarBar->currentText() == "Seconds"){
        int chosenWin = (ui->barSizeEdit->text()).toInt();
        int totalWin = system->getParam("samplingFreq") * chosenWin / system->getParam("varWin");
        system->setParam("varBarSize", totalWin);
    }
    else system->setParam("varBarSize", (ui->barSizeEdit->text()).toInt());
}

/**
 * @brief checkInputValues Checks the validity of input values for window parameters.
 * Throws an error message if the window value has been set to lower than the number of data points.
 */
void MainWindow::checkInputValues(bool winValueChanged, int win){

    if (winValueChanged == 1){
        QErrorMessage * error = new QErrorMessage(this);
        error->setWindowTitle("Input Error!");
        error->showMessage("Selected window size is greater than the minimum number of datapoints from an imported file! Minimum is used instead:\n" + QString::number(win) + " data points");
    }
}

/**
 * @brief populateCombos Populates combo boxes with file names
 * Takes imported file names and inserts them into all combo boxes in the application window
 */
void MainWindow::populateCombos(QStringList& fileNames){
    ui->fitPreviewCombo->clear();
    ui->fitPreviewCombo->addItems(fileNames);

    ui->comboFFTfiles->clear();
    ui->comboFFTfiles->addItems(fileNames);

    ui->comboFiltPreviewFiles->clear();
    ui->comboFiltPreviewFiles->addItems(fileNames);

    ui->comboPlotSettingsFiles->clear();
    ui->comboPlotSettingsFiles->addItems(fileNames);
}

/**
 * @brief MainWindow::on_actionImport_triggered Imports selected files.
 * Opens up the file dialog and allows multiple files to be imported via Reader object.
 */
void MainWindow::on_actionImport_triggered()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"),"/home/",tr("Text Files (*.txt)\n" "JPK out files (*.out)"));

    // If accepted
    if(!fileNames.isEmpty()){        

        system->doImport(fileNames);
        system->setPlotWidget(ui->plot);

        // Enable interface
        ui->processBox->setEnabled(true);

        // Feed the comboBox comboFileNames with list of File Names
        populateCombos(fileNames);

        // Set the parameters from the input values
        setState();

        // Set the message for the status bar
        ui->statusBar->showMessage("Successfully imported files..." ,5000);
    }
}

void MainWindow::setSystem(System *system){
    this->system = system;
}

/**
 * @brief MainWindow::on_fitPreviewButton_clicked Previews the fit on the selected file.
 * Before applying the fit to all files and overwriting them with processed ones, a user can preview if the fit is optimal.
 */
void MainWindow::on_fitPreviewButton_clicked()
{
    setState();
    int index = ui->fitPreviewCombo->currentIndex();
    system->doPreview(index, 0);
    ui->statusBar->showMessage("Flattening preview selected, using polynomial fit of order " + QString::number(system->getParam("flatOrder")),5000);
}

/**
 * @brief MainWindow::on_ApplyFlatButton_clicked Applies flattening to all files.
 * Calls the system object's member doFlat, to further call Flattener and create a QtConcurrent pool of processes for flattening.
 * @see System::doFlat
 */
void MainWindow::on_ApplyFlatButton_clicked()
{
    setState();
    checkInputValues(system->getParam("winValueChanged"), system->getParam("flatWin"));
    system->doFlat();
    ui->statusBar->showMessage("Flattening has been applied to the signal.",5000);
}

/**
 * @brief MainWindow::on_ApplyFlatButton_clicked Applies variance calculations to all files.
 * Calls the system object's member doVar, to further call the Variance instance and create a QtConcurrent pool of processes for calculations.
 * @see System::doFlat
 */
void MainWindow::on_ApplyVarButton_clicked()
{
    setState();
    checkInputValues(system->getParam("winValueChanged"), system->getParam("varWin"));
    system->doVar();
    system->doSubsequentialPlot(3);
}

/**
 * @brief MainWindow::on_actionExit_triggered Terminates the program.
 * Trigger to exit the program and quit the QCoreApplication
 */
void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

/**
 * @brief MainWindow::on_extractPlotButton_clicked Extracts the plot from the plotting widget into the notebook.
 * Calls the Notebook's member function extractPlot, which takes widget pointer and dimensions of a desired extract.
 * @see Notebook::extractPlot
 */
void MainWindow::on_extractPlotButton_clicked()
{
    double width =  ui->spinBoxWidth->value();
    double height = ui->spinBoxHeight->value();

    notebook.extractPlot(ui->plot, width, height);
}

/**
 * @brief MainWindow::on_extractSettingsButton_clicked Extracts currently used settings and pastes them into the notebook.
 * Calls the Notebook's memeber function extractSettings, which takes parameters as an input, to print them in the notebook.
 */
void MainWindow::on_extractSettingsButton_clicked()
{
    setState();
    std::map<std::string, int> params = system->getAllParams();
    notebook.extractSettings(params);
}

/**
 * @brief MainWindow::on_saveNotebookButton_clicked Saves the notebook as a PDF file on the file system.
 * Opens up a dialog to select a path where to store the printed PDF of a notebook, by Notebook's saveNotebook function.
 * @see Notebook::saveNotebook
 */
void MainWindow::on_saveNotebookButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document...", qApp->applicationDirPath(), "*.pdf");
    notebook.saveNotebook(fileName);
}

/**
 * @brief MainWindow::on_clearNotebookButton_clicked Clears all the notes form the notebook.
 * After an affirmative response, removes all the items from the notebook, by using Notebook's function clearNotes().
 * @see Notebook::clearNotes
 */
void MainWindow::on_clearNotebookButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Notebook", "Would you like to clear the netbook?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        notebook.clearNotes();
    }
}

/**
 * @brief MainWindow::on_applyCutoffButton_clicked Applies data cutting based on a threshold value.
 * Calls up the system's members doVarCut for data cutting and doSubsequentialPlot for plotting the variance data one file after the other.
 * @see System::doVarCut
 * @see System::doSubsequentialPlot
 */
void MainWindow::on_applyCutoffButton_clicked()
{
    system->doVarCut((ui->editCutoffVar->text()).toDouble());
    system->doSubsequentialPlot(3);
}

/**
 * @brief MainWindow::on_applyVarBarsButton_clicked Calculates variance averages and plots bar chart.
 * Calls up the system's functions doVarBars for calculating the average of variance for a selected range, and doBarPlot for plotting the values in a bar plot.
 * @see System::doVarBars
 * @see System::doBarPlot
 */
void MainWindow::on_applyVarBarsButton_clicked()
{
    setState();

    system->doVarBars();
    system->doBarPlot();
}

/**
 * @brief MainWindow::on_boxPlotButton_clicked Calculates variance statistics and plots them in a box plot.
 * Calls up the system's functions doVarBox for calculating quartiles, IQR, median, and doBoxPlot for plotting the values in a box plot.
 * @see System::doVarBox
 * @see System::doBoxPlot
 */
void MainWindow::on_boxPlotButton_clicked()
{
    system->doVarBox();
    system->doBoxPlot();
}

/**
 * @brief MainWindow::on_calcSingleFFTButton_clicked Calculates a FFT spectrum of a single file under selection.
 * After saving all the input values of the application window, it calls the System's doPreview function for FFT creation and plotting.
 * @see System::doPreview
 */
void MainWindow::on_calcSingleFFTButton_clicked()
{
    setState();
    int index = ui->comboFiltPreviewFiles->currentIndex();
    system->doPreview(index, 2);
}

/**
 * @brief MainWindow::on_applyMovAvgButton_clicked Calculates the moving average on all files.
 * After the input value saving and verification, it calls System's doFilt function to apply moving average on all files in separate threads.
 * @see System::doFilt
 */
void MainWindow::on_applyMovAvgButton_clicked()
{
    setState();
    checkInputValues(system->getParam("winValueChanged"), system->getParam("filtWin"));
    system->doFilt();
    ui->statusBar->showMessage("Filtering has been applied to the signal.",5000);
}

/**
 * @brief MainWindow::on_plotButton_clicked Plots the selected option.
 * Takes the index of the selected file and plots it. Depending on the choice of the plot, it may be a single plot or all files one after the other.
 * @see System::doPlot
 * @see System::doSubsequentialPlot
 */
void MainWindow::on_plotButton_clicked()
{
    setState();
    int pageIndex = ui->processBox->currentIndex();
    int fileIndex = ui->comboPlotSettingsFiles->currentIndex();

    if(ui->radioSignleFile->isChecked()){
        system->doPlot(fileIndex, pageIndex);
    }
    else{
        system->doSubsequentialPlot(pageIndex);
    }
}

/**
 * @brief MainWindow::on_filterPreviewButton_clicked Previews a moving average filtering.
 * Without affectin all the files, it previews the filter by calling System's doPreview function.
 * @see System::doPreview
 */
void MainWindow::on_filterPreviewButton_clicked()
{
    setState();
    int index = ui->comboFiltPreviewFiles->currentIndex();
    system->doPreview(index, 1);
    ui->statusBar->showMessage("Filtering preview selected, using moving average of window: " + QString::number(system->getParam("filtWin")),5000);
}

/**
 * @brief MainWindow::on_actionAppend_triggered Appends the selected file(s) onto already imported list.
 * Without changing or overwriting already imported files, function appends selected files by doAppend and their filenames in all combo boxes.
 * @see System::doAppend
 */
void MainWindow::on_actionAppend_triggered()
{
    ui->processBox->setEnabled(false);

    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"),"/home/",tr("Text Files (*.txt)\n" "JPK out files (*.out)"));

    if(!fileNames.isEmpty()){
        system->doAppend(fileNames);

        // Feed the comboBox comboFileNames with list of File Names
        ui->fitPreviewCombo->addItems(fileNames);
        ui->comboFFTfiles->addItems(fileNames);
        ui->comboFiltPreviewFiles->addItems(fileNames);
        ui->comboPlotSettingsFiles->addItems(fileNames);

        // Set the message for the status bar
        ui->statusBar->showMessage("Successfully appended files..." , 5000);
    }
    ui->processBox->setEnabled(true);
}

/**
 * @brief MainWindow::on_actionManipulation_triggered Opens up a manipulation window.
 * It takes filenames and feeds them to the Manipulation window combo box. Calls the window and then checks if changes in the file order has taken place.
 */
void MainWindow::on_actionManipulation_triggered()
{
    setState();

    // Take filenames from the appropriate container
    vector<string> fileNames = system->getFileNames();

    Manipulation * manipulation = new Manipulation;
    manipulation->setVecList(fileNames);
    manipulation->setSampleFreq(system->getParam("samplingFreq"));

    manipulation->exec();

    // If the order of files has been changed
    bool isOrderChanged = manipulation->ifOrderChanged();
    if (isOrderChanged == true){

        vector<size_t> newIndices = manipulation->getVecOrder();

        system->doReorder(newIndices);

        // Populate combo boxes with new order of filenames
        QStringList newComboItems;
        vector<string> newFileNames = system->getFileNames();

        for (unsigned int i = 0; i < newFileNames.size(); ++i){
            newComboItems.append(QString::fromStdString(newFileNames[i]));
        }
        populateCombos(newComboItems);

        // Set the sampling frequency and downsampling options after accepting the window
        system->setParam("samplingFreq", manipulation->getSampleFreq());
        ui->editSamplingFreq->setValue(system->getParam("samplingFreq"));
        system->setParam("isDownsampled", manipulation->ifDownsampling());
        system->setParam("downSamplingFreq", manipulation->getNewSampleFreq());

    }
}

void MainWindow::on_actionFlattening_triggered()
{
    ui->processBox->setCurrentIndex(0); // Changes focus of the process box to Flattening section
}

void MainWindow::on_actionFiltering_triggered()
{
    ui->processBox->setCurrentIndex(1); // Changes focus of the process box to Filtering section
}

void MainWindow::on_actionFFT_triggered()
{
    ui->processBox->setCurrentIndex(2); // Changes focus of the process box to FFT section
}

void MainWindow::on_actionVariance_triggered()
{
    ui->processBox->setCurrentIndex(3); // Changes focus of the process box to Variance section
}

/**
 * @brief MainWindow::on_actionAbout_triggered Opens up the About information.
 * Shows the author information stored in a QString.
 */
void MainWindow::on_actionAbout_triggered()
{
    QString about_text;
    about_text = "NanoSignal: Signal analysis toolbox.\nAuthor: Petar Stupar\nCollective Copyright Holder\n";
    about_text += "Copyright (C) 2017\nLicensed under the GPLv3.\n";

    //QMessageBox::about(this, "About NanoSignal", about_text);
    QMessageBox abouter;
    abouter.setIconPixmap(QPixmap(":/new/prefix1/Splash/a15.png"));
    abouter.setInformativeText(about_text);
    abouter.setDefaultButton(QMessageBox::Ok);
    abouter.show();
    abouter.exec();

}

/**
 * @brief MainWindow::on_actionManual_triggered Opens up the manual of how to use the software.
 * Gives the manual of software usage.
 */
void MainWindow::on_actionManual_triggered()
{
    // Should be changed to open a file from resources.
    QDesktopServices::openUrl(QUrl::fromLocalFile("://new/prefix1/Documentation/index.html"));
}

