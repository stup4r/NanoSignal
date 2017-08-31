#include "filter.h"

Filter::Filter()
{

}
Filter::~Filter(){

}

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
    (*datalink.file).erase((*datalink.file).begin(), (*datalink.file).begin() + win);
}
