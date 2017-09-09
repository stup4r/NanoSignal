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
    var->doProcessMulti(this->data);
    delete var;
}
void System::doFlat(){

    Flattener * flat = new Flattener;
    flat->setIsWindowed(getParam("flatWindowed"));
    flat->setOrder(getParam("flatOrder"));
    flat->setWindow(getParam("flatWin"));
    flat->doProcessMulti(this->data);
    delete flat;
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
