#include "system.h"

System::System()
{

}
System::~System(){

}

Data& System::getData(){
    return this->data;
}

void System::setPlotWidget(CustomPlotZoom* plotWidget){
    this->plotWidget = plotWidget;
}

void System::checkInputValue(vector<vector<dataType> >& someData, int& N){
    setParam("winValueChanged", 0);
    int minimum = someData[0].size();
    int vecSize;

    for (unsigned int i = 0; i < someData.size(); ++i){
        vecSize = someData[i].size();
        minimum = (vecSize<minimum)?vecSize:minimum;
    }
    if (N > minimum){
        N = minimum;
        setParam("winValueChanged", 1);
    }
}

void System::doImport(QStringList fileNames){

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

    // Imports files
    Reader * reader = new Reader;
    reader->setIsDownsampled(data.parameters["isDownsampled"]);
    reader->setDownSamplingStep(data.parameters["downSamplingFreq"]);
    reader->doProcessMulti(this->data);
    delete reader;
    data.parameters["isDownsampled"] = 0;
}

void System::doAppend(QStringList fileNames){

    // Convert QStringList into vector<string>
    std::vector<string> fileNamesVec;
    for (int i = 0; i < fileNames.size(); ++i) {
        std::string tmp = fileNames[i].toStdString();
        fileNamesVec.push_back(tmp);
    }

    // Append chosen files
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
}

void System::setParam(std::string s, int n){
    this->data.parameters[s] = n;
}
int System::getParam(std::string s){
    return this->data.parameters[s];
}

void System::doVar(){

    Variance * var = new Variance;
    var->setWindow(getParam("varWin"));
    checkInputValue(this->data.defData, this->data.parameters["varWin"]);
    var->doProcessMulti(this->data);
    delete var;
}
void System::doFlat(){

    Flattener * flat = new Flattener;
    flat->setIsWindowed(getParam("flatWindowed"));
    flat->setOrder(getParam("flatOrder"));
    flat->setWindow(getParam("flatWin"));
    checkInputValue(this->data.defData, this->data.parameters["flatWin"]);
    flat->doProcessMulti(this->data);
    delete flat;
    setParam("isFlattening", 1);
}
void System::doFilt(){
    Filter * filter = new Filter;
    filter->setWindow(getParam("filtWin"));
    filter->doProcessMulti(this->data);
    delete filter;
}
void System::doFFT(){

}
void System::doVarCut(double n){
    Variance * var = new Variance;
    var->cutoffVariancce(this->data.varData, n);
    delete var;
}
void System::doVarBars(){
    Variance * var = new Variance;
    var->averageBars(this->data);
    delete var;
}
void System::doVarBox(vector<vector<dataType> >& statistic){

    Variance * var = new Variance;
    var->getBoxplotStat(this->data.varData, statistic);
    delete var;
}
void System::doSubsequentialPlot(int s){
    Plotter * plotter = new Plotter(this->plotWidget);
    plotter->subsequentialPlot(this->data, s);
    delete plotter;
}
void System::doPreview(int index, int s){
    DataLink datalink;
    datalink.name = &(this->data.fileNames[index]);
    vector<dataType> processedData = data.defData[index];
    datalink.file = &processedData;

    switch (s) {
    case 0: // Flatten
    {
        Flattener * flat = new Flattener;
        flat->setIsWindowed(getParam("flatWindowed"));
        flat->setOrder(getParam("flatOrder"));
        flat->setWindow(getParam("flatWin"));
        checkInputValue(this->data.defData, this->data.parameters["flatWin"]);
        flat->doProcessOne(datalink);
        delete flat;

        Plotter * plotter = new Plotter(this->plotWidget);
        plotter->plotProcessPreview(this->data.defData[index], processedData);
        delete plotter;

        break;
    }
    case 1: // Filter
    {
        Filter * filter = new Filter;
        filter->setWindow(getParam("filtWin"));
        filter->doProcessOne(datalink);
        delete filter;

        Plotter * plotter = new Plotter(this->plotWidget);
        plotter->plotProcessPreview(this->data.defData[index], processedData);
        delete plotter;

        break;
    }
    case 2: // FFT
    {
        dataType FS = getParam("samplingFreq");
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
        processedData.erase(processedData.begin());

        Plotter * plotter = new Plotter(this->plotWidget);
        plotter->setMinMaxRange(0, FS/2);
        plotter->plot(freq, processedData, 2);
        delete plotter;
        break;
    }
    default:
        break;
    }
    processedData.clear();
}
