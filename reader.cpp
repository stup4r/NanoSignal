#include "reader.h"
#include <iterator>
#include <algorithm>
#include <fstream>
// Ajajaj...

Reader::Reader()
{

}
Reader::~Reader(){

}

void Reader::setIsDownsampled(bool ds){
    this->isDownsampled = ds;
}
void Reader::setDownSamplingStep(int dss){
    this->downSamplingStep = dss;
}

/**
 * Function called to open a (one only) file and import its data into a vector.
 * @param name - string that coresponds to the filename of the file being imported (and its path).
 * @param mydata - reference to the vector where data will be stored.
 */

void Reader::doProcessOne(DataLink& datalink){

    ifstream is((*datalink.name).c_str());
    istream_iterator<dataType> start(is), end;
    vector<dataType> tmp(start, end);

    if (this->isDownsampled == true) {
        vector<dataType> tmp2;
        for(unsigned int i = 0; i<tmp.size(); i += (this->downSamplingStep)){
            tmp2.push_back(tmp[i]);
        }
        (*datalink.file) = tmp2;
        tmp2.clear();
    }

    else {
    (*datalink.file) = tmp;
    tmp.clear();
    }
}
