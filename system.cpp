/*************************************************************************
 *
 *  NanoSignal: Signal analysis toolbox.
 *  Copyright (C) 2017  Petar Stupar
 *  Collective Copyright Holder.
 *  Licensed under the GPLv3.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ************************************************************************/

#include "system.h"

System::System()
{

}
System::~System(){

}

vector<string> System::getFileNames(){
    return this->data.fileNames;
}
void System::doReorder(vector<size_t>& orders){
    this->data.reorderData(orders);
}

void System::setPlotWidget(CustomPlotZoom* plotWidget){
    this->plotWidget = plotWidget;
}
std::map<std::string, int> System::getAllParams(){
    return this->data.parameters;
}

/**
 * @brief System::checkInputValue Function check input value for a window parameter.
 * It makes no sense to set a window larger than the number of available points. Therefore, this function automatically sets the window size equal to the minimum number of points of a file within the vector of files.
 * @param someData Vector of files (vectors of dataType)
 * @param N Selected window size
 */
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

/**
 * @brief System::doImport Imports files using the instantiation of the class Reader
 * @param fileNames A list of selected filenames to import.
 */
void System::doImport(QStringList fileNames){

    //Clearing up the imported data first
    this->data.clearAll();
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

/**
 * @brief System::doAppend Appends files to the already imported ones.
 * @param fileNames A list of selected filenames to append.
 */
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

/**
 * @brief System::doVar Function does variance calculations by calling doProcessMulti of the object of class Variance.
 */
void System::doVar(){

    Variance * var = new Variance;
    var->setWindow(getParam("varWin"));
    checkInputValue(this->data.defData, this->data.parameters["varWin"]);
    var->doProcessMulti(this->data);
    delete var;
}

/**
 * @brief System::doFlat Function does flattening by calling doProcessMulti of the object of class Flattening.
 */
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

/**
 * @brief System::doFilt Function does filtering by calling doProcessMulti of the object of class Filter.
 */
void System::doFilt(){

    Filter * filter = new Filter;
    filter->setWindow(getParam("filtWin"));
    filter->doProcessMulti(this->data);
    delete filter;
    setParam("isFiltering", 1);
}
void System::doFFT(){
    // To be implemented, only if necessary, as files are larger and will need to be stored.
}

/**
 * @brief System::doVarCut Applies data cutting based on a threshold value.
 * @param n Threshold value
 */
void System::doVarCut(double n){

    Variance * var = new Variance;
    var->cutoffVariancce(this->data.varData, n);
    delete var;
}

/**
 * @brief System::doVarBars Calculates variance averages.
 */
void System::doVarBars(){
    Variance * var = new Variance;
    var->averageBars(this->data);
    delete var;
}

/**
 * @brief System::doVarBox Calculates variance statistics and plots them in a box plot.
 * Calls up the Variance's method getBoxplotStat for calculating quartiles, IQR, median.
 */
void System::doVarBox(){
    Variance * var = new Variance;
    var->getBoxplotStat(this->data);
    delete var;
}

/**
 * @brief System::doSubsequentialPlot Plots files one after the other in a single plot.
 * @param s Swich statement modifier: 3 is the variance plot.
 */
void System::doSubsequentialPlot(int s){

    Plotter * plotter = new Plotter(this->plotWidget);
    plotter->subsequentialPlot(this->data, s);
    delete plotter;
}

/**
 * @brief System::doPreview Previews a processing step of choice, dictated by the int s.
 * @param index Chosen file (vector index of the chosen file).
 * @param s Swich statement modifier: 0 is flattening, 1 is filtering, 2 is FFT.
 */
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

        // Frequency vector generation
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

/**
 * @brief System::doBarPlot Plots variance averages as bars.
 */
void System::doBarPlot(){

    Plotter * plotter = new Plotter(this->plotWidget);
    plotter->varBarPlot(this->data);
    delete plotter;
}

/**
 * @brief System::doBoxPlot Creates a box plot by using data from the data container.
 */
void System::doBoxPlot(){

    Plotter * plotter = new Plotter(this->plotWidget);
    plotter->varBoxPlot(this->data);
    delete plotter;
}

/**
 * @brief System::doPlot Regular plot of a single file, depening on the int s.
 * @param fileIndex Index of the data vectors pointing to the chosen file (filename).
 * @param pageIndex Switch case modifier: 0 and 1 - deflection data, 2 - FFT, 3 - variance.
 */
void System::doPlot(int fileIndex, int pageIndex){

    Plotter * plotter = new Plotter(this->plotWidget);
    plotter->plot(this->data, fileIndex, pageIndex);

}
