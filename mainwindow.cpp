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

    // Set up Notebook object
    notebook.setTextEdit(ui->notebookTextEdit);
    QCPDocumentObject *plotObjectHandler = new QCPDocumentObject(this);
    ui->notebookTextEdit->document()->documentLayout()->registerHandler(QCPDocumentObject::PlotTextFormat, plotObjectHandler);

}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::checkInputValues(bool winValueChanged, int win){

    if (winValueChanged == 1){
        QErrorMessage * error = new QErrorMessage(this);
        error->setWindowTitle("Input Error!");
        error->showMessage("Selected window size is greater than the minimum number of datapoints from an imported file! Minimum is used instead:\n" + QString::number(win) + " data points");
    }
}

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
        setState();

        // Set the message for the status bar
        ui->statusBar->showMessage("Successfully imported files..." ,5000);
    }
}

void MainWindow::setSystem(System *system){
    this->system = system;
}

void MainWindow::on_fitPreviewButton_clicked()
{
    setState();
    int index = ui->fitPreviewCombo->currentIndex();
    system->doPreview(index, 0);
    ui->statusBar->showMessage("Flattening preview selected, using polynomial fit of order " + QString::number(system->getParam("flatOrder")),5000);
}

void MainWindow::on_ApplyFlatButton_clicked()
{
    setState();
    checkInputValues(system->getParam("winValueChanged"), system->getParam("flatWin"));
    system->doFlat();
    ui->statusBar->showMessage("Flattening has been applied to the signal.",5000);
}

void MainWindow::on_ApplyVarButton_clicked()
{
    setState();
    checkInputValues(system->getParam("winValueChanged"), system->getParam("varWin"));
    system->doVar();
    system->doSubsequentialPlot(3);
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_extractPlotButton_clicked()
{
    double width =  ui->spinBoxWidth->value();
    double height = ui->spinBoxHeight->value();

    notebook.extractPlot(ui->plot, width, height);
}

void MainWindow::on_extractSettingsButton_clicked()
{
    setState();
    std::map<std::string, int> params = system->getAllParams();
    notebook.extractSettings(params);
}

void MainWindow::on_saveNotebookButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document...", qApp->applicationDirPath(), "*.pdf");
    notebook.saveNotebook(fileName);
}

void MainWindow::on_clearNotebookButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Notebook", "Would you like to clear the netbook?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        notebook.clearNotes();
    }
}

void MainWindow::on_applyCutoffButton_clicked()
{
    system->doVarCut((ui->editCutoffVar->text()).toDouble());
    system->doSubsequentialPlot(3);
}

void MainWindow::on_applyVarBarsButton_clicked()
{
    setState();

    system->doVarBars();
    system->doBarPlot();
}

void MainWindow::on_boxPlotButton_clicked()
{
    system->doVarBox();
    system->doBoxPlot();
}

void MainWindow::on_calcSingleFFTButton_clicked()
{
    setState();
    int index = ui->comboFiltPreviewFiles->currentIndex();
    system->doPreview(index, 2);
}

void MainWindow::on_applyMovAvgButton_clicked()
{
    setState();
    checkInputValues(system->getParam("winValueChanged"), system->getParam("filtWin"));
    system->doFilt();
    ui->statusBar->showMessage("Filtering has been applied to the signal.",5000);
}

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

void MainWindow::on_filterPreviewButton_clicked()
{
    setState();
    int index = ui->comboFiltPreviewFiles->currentIndex();
    system->doPreview(index, 1);
    ui->statusBar->showMessage("Filtering preview selected, using moving average of window: " + QString::number(system->getParam("filtWin")),5000);
}

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

void MainWindow::on_actionManipulation_triggered()
{
    setState();
    vector<string> fileNames = system->getFileNames();

    Manipulation * manipulation = new Manipulation;
    manipulation->setVecList(fileNames);
    manipulation->setSampleFreq(system->getParam("samplingFreq"));

    manipulation->exec();

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

        system->setParam("samplingFreq", manipulation->getSampleFreq());
        ui->editSamplingFreq->setValue(system->getParam("samplingFreq"));
        system->setParam("isDownsampled", manipulation->ifDownsampling());
        system->setParam("downSamplingFreq", manipulation->getNewSampleFreq());

    }
}

void MainWindow::on_actionFlattening_triggered()
{
    ui->processBox->setCurrentIndex(0);
}

void MainWindow::on_actionFiltering_triggered()
{
    ui->processBox->setCurrentIndex(1);
}

void MainWindow::on_actionFFT_triggered()
{
    ui->processBox->setCurrentIndex(2);
}

void MainWindow::on_actionVariance_triggered()
{
    ui->processBox->setCurrentIndex(3);
}

void MainWindow::on_actionAbout_triggered()
{
    QString about_text;
    about_text = "Author: Awesome Me\n";
    about_text += "Something else\n";
    about_text += "(C) NanoSignal (R)\n";

    QMessageBox::about(this, "About NanoSignal", about_text);
}

void MainWindow::on_actionManual_triggered()
{
    // Should be changed to open a file from resources.
    QDesktopServices::openUrl(QUrl("file:///home/kinase/Sources/Qt/NanoSignal_10_7/manualTest.pdf"));
}

