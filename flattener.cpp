#include "flattener.h"

Flattener::Flattener()
{

}
Flattener::~Flattener(){

}

/**
 * @brief Flattener::doProcessOne Flattening of the signal.
 * Signal is being flattened by subtracting polynomial fit from a signal.
 * Processing is done in a window (cuts data in separate vectors of the same size and does processing under them, then gathers them back together).
 * In two loops (one over the names of files, and another one over each vector), it creates windowed X and Y points, fits them, subtracts and merges back.
 * This way makes sure that some signals that have a huge drift do not loose information after flattening.
 * @param datalink Helper struct that connects (references) to a single file and its file name.
 */
void Flattener::doProcessOne(DataLink& datalink){
    vector<dataType> difference;

    vector<dataType> dataX((*datalink.file).size());
    iota(dataX.begin(), dataX.end(), 0);

    if(this->isWindowed == true) {
        vector<dataType> fitParts;
        for (unsigned int i = 1; i <= (*datalink.file).size()/(this->windowSize); ++i) {
            vector<double> cutData(&(*datalink.file)[(this->windowSize)*(i-1)], &(*datalink.file)[i*(this->windowSize)]);
            vector<double> cutXData(&dataX[(this->windowSize)*(i-1)], &dataX[i*(this->windowSize)]);
            fitParts = polynomialFit(cutXData, cutData, this->order);
            difference.insert(difference.end(), fitParts.begin(), fitParts.end());

            // Clearing up vectors
            cutData.clear();
            cutXData.clear();
            fitParts.clear();
        }
    }

    else {
        difference = polynomialFit(dataX, (*datalink.file), this->order);
    }

    dataX.clear();

    (*datalink.file).clear();

    // Overwrites the vector!
    (*datalink.file) = difference;
    difference.clear();
}
