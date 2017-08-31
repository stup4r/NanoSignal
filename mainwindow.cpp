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

    this->data.parameters["samplingFreq"] = (ui->editSamplingFreq->text()).toInt();

    this->data.parameters["flatWindowed"] = ui->isWindowedCheck->isChecked();
    this->data.parameters["flatOrder"] = (ui->flatOrderEdit->text()).toInt();

    if (ui->unitsFlatWin->currentText() == "Seconds"){
        int chosenWin = (ui->flatWinEdit->text()).toInt();
        this->data.parameters["flatWin"] = data.parameters["samplingFreq"] * chosenWin;
    }
    else this->data.parameters["flatWin"] = (ui->flatWinEdit->text()).toInt();

    if (ui->unitsFiltWin->currentText() == "Seconds"){
        int chosenWin = (ui->editMovAvgWin->text()).toInt();
        this->data.parameters["filtWin"] = data.parameters["samplingFreq"] * chosenWin;
    }
    else this->data.parameters["filtWin"] = (ui->editMovAvgWin->text()).toInt();

    if (ui->unitsVarWin->currentText() == "Seconds"){
        int chosenWin = (ui->varWinEdit->text()).toInt();
        this->data.parameters["varWin"] = data.parameters["samplingFreq"] * chosenWin;
    }
    else this->data.parameters["varWin"] = (ui->varWinEdit->text()).toInt();

    if (ui->unitsVarBar->currentText() == "Seconds"){
        int chosenWin = (ui->barSizeEdit->text()).toInt();
        this->data.parameters["varBarSize"] = data.parameters["samplingFreq"] * chosenWin / data.parameters["varWin"];
    }
    else this->data.parameters["varBarSize"] = (ui->barSizeEdit->text()).toInt();

}

void MainWindow::checkInputValues(vector<vector<dataType> >& someData, int& N){

    int minimum = someData[0].size();
    int vecSize;

    for (unsigned int i = 0; i < someData.size(); ++i){
        vecSize = someData[i].size();
        minimum = (vecSize<minimum)?vecSize:minimum;
    }

    if (N > minimum){
        QErrorMessage * error = new QErrorMessage(this);
        error->setWindowTitle("Input Error!");
        error->showMessage("Selected window size is greater than the minimum number of datapoints from an imported file! Minimum is used instead:\n" + QString::number(minimum) + " data points");
        N = minimum;
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

        //Clearing up the imported data first
        data.clearAll();
        importing(fileNames);
    }
}

void MainWindow::importing(QStringList fileNames){

    // Convert QStringList into vector<string>
    std::vector<string> fileNamesVec;
    for (int i = 0; i < fileNames.size(); ++i) {
        std::string tmp = fileNames[i].toStdString();
        fileNamesVec.push_back(tmp);
    }
    this->data.fileNames = fileNamesVec;

    // Allocate data files
    for (unsigned int i = 0; i<data.fileNames.size(); ++i){
        data.defData.push_back({0});
        data.varData.push_back({0});
    }

    Reader * reader = new Reader;
    reader->setIsDownsampled(data.parameters["isDownsampled"]);
    reader->setDownSamplingStep(data.parameters["downSamplingFreq"]);
    reader->doProcessMulti(this->data);
    delete reader;
    data.parameters["isDownsampled"] = 0;

    // Enable interface
    ui->processBox->setEnabled(true);

    // Feed the comboBox comboFileNames with list of File Names
    populateCombos(fileNames);
    setState();
    // Set the message for the status bar
    ui->statusBar->showMessage("Successfully imported files..." ,5000);

}

void MainWindow::on_fitPreviewButton_clicked()
{
    setState();
    checkInputValues(data.defData, data.parameters["flatWin"]);

    Flattener * flat = new Flattener;
    flat->setIsWindowed(this->data.parameters["flatWindowed"]);
    flat->setOrder(this->data.parameters["flatOrder"]);
    flat->setWindow(this->data.parameters["flatWin"]);

    DataLink datalink;
    int index = ui->fitPreviewCombo->currentIndex();
    datalink.name = &(data.fileNames[index]);
    vector<dataType> fits = data.defData[index];
    datalink.file = &fits;

    flat->doProcessOne(datalink);
    delete flat;

    Plotter * plotter = new Plotter(ui->plot);
    plotter->plotProcessPreview(data.defData[index], fits);
    delete plotter;

    ui->statusBar->showMessage("Flattening preview selected, using polynomial fit of order " + QString::number(data.parameters["flatOrder"]),5000);
}

void MainWindow::on_ApplyFlatButton_clicked()
{
    setState();
    checkInputValues(data.defData, data.parameters["flatWin"]);

    Flattener * flat = new Flattener;
    flat->setIsWindowed(this->data.parameters["flatWindowed"]);
    flat->setOrder(this->data.parameters["flatOrder"]);
    flat->setWindow(this->data.parameters["flatWin"]);

    flat->doProcessMulti(this->data);

    delete flat;
    ui->statusBar->showMessage("Flattening has been applied to the signal.",5000);
    this->data.parameters["isFlattening"] = 1;
}

void MainWindow::on_ApplyVarButton_clicked()
{
    setState();
    checkInputValues(data.defData, data.parameters["varWin"]);

    Variance * var = new Variance;
    var->setWindow(this->data.parameters["varWin"]);

    var->doProcessMulti(this->data);

    delete var;

    Plotter * plotter = new Plotter(ui->plot);
    plotter->subsequentialPlot_Var(data);
    delete plotter;

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
    notebook.extractSettings(data.parameters);
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
    Variance * var = new Variance;
    var->cutoffVariancce(data.varData, (ui->editCutoffVar->text()).toDouble());
    delete var;

    Plotter * plotter = new Plotter(ui->plot);
    plotter->subsequentialPlot_Var(data);
    delete plotter;
}

void MainWindow::on_applyVarBarsButton_clicked()
{
    setState();

    Variance * var = new Variance;
    var->averageBars(data);
    delete var;

    Plotter * plotter = new Plotter(ui->plot);
    plotter->varBarPlot(data);
    delete plotter;
}

void MainWindow::on_boxPlotButton_clicked()
{
    vector<vector<dataType> > statistic;

    Variance * var = new Variance;
    var->getBoxplotStat(data.varData, statistic);
    delete var;

    Plotter * plotter = new Plotter(ui->plot);
    plotter->varBoxPlot(statistic, data.fileNames);
    delete plotter;
}

void MainWindow::on_calcSingleFFTButton_clicked()
{
    setState();

    dataType FS = data.parameters["samplingFreq"];

    DataLink datalink;
    int index = ui->comboFFTfiles->currentIndex();
    datalink.name = &(data.fileNames[index]);
    vector<dataType> z = data.defData[index];
    datalink.file = &z;

    Fourier * fourier = new Fourier;
    fourier->setSamplingFreq(FS);
    fourier->doProcessOne(datalink);
    unsigned long N = fourier->getSizeN();
    delete fourier;


    vector<dataType> freq;
    for (unsigned int i=0; i<N/2; i++) {
        freq.push_back(i * FS / N);
    }

    freq.erase(freq.begin());
    z.erase(z.begin());

    Plotter * plotter = new Plotter(ui->plot);
    plotter->setMinMaxRange(0, FS/2);
    plotter->plotFFTPreview(freq, z);
    delete plotter;
}

void MainWindow::on_applyMovAvgButton_clicked()
{
    setState();
    checkInputValues(data.defData, data.parameters["filtWin"]);

    Filter * filter = new Filter;
    filter->setWindow(this->data.parameters["filtWin"]);
    filter->doProcessMulti(this->data);
    delete filter;

    ui->statusBar->showMessage("Filtering has been applied to the signal.",5000);
    this->data.parameters["isFiltering"] = 1;
}

void MainWindow::on_plotButton_clicked()
{
    Plotter * plotter = new Plotter(ui->plot);
    int pageIndex = ui->processBox->currentIndex();
    int fileIndex = ui->comboPlotSettingsFiles->currentIndex();

    if(ui->radioSignleFile->isChecked()){
        if (pageIndex == 0 or pageIndex == 1){
            plotter->plotSingle(data.defData[fileIndex]);
        }
        else{
            plotter->plotSingle(data.varData[fileIndex]);
        }
    }

    delete plotter;
}

void MainWindow::on_filterPreviewButton_clicked()
{
    setState();
    checkInputValues(data.defData, data.parameters["filtWin"]);

    DataLink datalink;
    int index = ui->comboFiltPreviewFiles->currentIndex();
    datalink.name = &(data.fileNames[index]);
    vector<dataType> filt = data.defData[index];
    datalink.file = &filt;

    Filter * filter = new Filter;
    filter->setWindow(this->data.parameters["filtWin"]);
    filter->doProcessOne(datalink);
    delete filter;

    Plotter * plotter = new Plotter(ui->plot);
    plotter->plotProcessPreview(data.defData[index], filt);
    delete plotter;

    ui->statusBar->showMessage("Filtering preview selected, using moving average of window: " + QString::number(data.parameters["filtWin"]),5000);
}

void MainWindow::on_actionAppend_triggered()
{
    ui->processBox->setEnabled(false);

    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open Files"),"/home/",tr("Text Files (*.txt)\n" "JPK out files (*.out)"));

    // Convert QStringList into vector<string>
    std::vector<string> fileNamesVec;
    for (int i = 0; i < fileNames.size(); ++i) {
        std::string tmp = fileNames[i].toStdString();
        fileNamesVec.push_back(tmp);
    }

    Reader * reader = new Reader;
    for (unsigned int i = 0; i < fileNamesVec.size(); ++i){
        data.fileNames.push_back(fileNamesVec[i]);
        data.defData.push_back({0});
        data.varData.push_back({0});

        int index = data.fileNames.size() - 1;

        DataLink datalink;
        datalink.name = &(data.fileNames[index]);
        datalink.file = &(data.defData[index]);

        reader->doProcessOne(datalink);
    }

    delete reader;

    // Feed the comboBox comboFileNames with list of File Names

    ui->fitPreviewCombo->addItems(fileNames);
    ui->comboFFTfiles->addItems(fileNames);
    ui->comboFiltPreviewFiles->addItems(fileNames);
    ui->comboPlotSettingsFiles->addItems(fileNames);

    ui->processBox->setEnabled(true);

    // Set the message for the status bar
    ui->statusBar->showMessage("Successfully appended files..." , 5000);

}

void MainWindow::on_actionManipulation_triggered()
{
    setState();
    Manipulation * manipulation = new Manipulation;
    manipulation->setVecList(data.fileNames);
    manipulation->setSampleFreq(data.parameters["samplingFreq"]);

    manipulation->exec();

    bool isOrderChanged = manipulation->ifOrderChanged();

    if (isOrderChanged == true){

        vector<size_t> newIndices = manipulation->getVecOrder();
        data.reorderData(newIndices);

        // Populate combo boxes with new order of filenames
        QStringList newComboItems;
        for (unsigned int i = 0; i < data.fileNames.size(); ++i){
            newComboItems.append(QString::fromStdString(data.fileNames[i]));
        }
        populateCombos(newComboItems);

        data.parameters["samplingFreq"] = manipulation->getSampleFreq();
        ui->editSamplingFreq->setValue(data.parameters["samplingFreq"]);
        data.parameters["isDownsampled"] = manipulation->ifDownsampling();
        data.parameters["downSamplingFreq"] = manipulation->getNewSampleFreq();

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
