#include "data.h"

Data::Data()
{

}
Data::~Data(){

}

void Data::clearAll(){
    this->defData.clear();
    this->varData.clear();
    this->fileNames.clear();
    this->varMeans.clear();
    this->statistic.clear();
}

void Data::reorderData(vector<size_t>& order){
    reorderVec(this->defData, order);
    reorderVec(this->varData, order);
    reorderVec(this->fileNames, order);
    this->varMeans.clear();
    this->statistic.clear();
}
