#include "filter.h"

Filter::Filter()
{

}
Filter::~Filter(){

}

/**
 * @brief Filter::doProcessOne Filtering done in one thread.
 * The function does moving average filtering in one thread for a signle file. It is called by doProcesMulti in a QtConcurrent::map.
 * @param datalink Helper struct that connects (references) to a single file and its file name.
 */
void Filter::doProcessOne(DataLink& datalink){

    int win = this->windowSize;
    size_t vectorSize = (*datalink.file).size();

    dataType sum = 0;
    int cntr = 0;
    for (unsigned int i = 0; i < vectorSize; ++i){

        sum += (*datalink.file)[i];
        cntr++;
        if (cntr >= win){
            (*datalink.file)[i] = sum / (double) win;
            sum -= (*datalink.file)[cntr - win];
        }
    }
    // Removes the rest (unprocessed data)
    (*datalink.file).erase((*datalink.file).begin(), (*datalink.file).begin() + win);
}
