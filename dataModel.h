// LP
#ifndef DATAMODEL_H
#define DATAMODEL_H

#include "data.h"
#include "reader.h"

class DataModel {
public:
    DataModel(); // init and data
    ~DataModel();
    
    void importing(QStringList);
    void appending(QStringList);
    
    Data& getData() {
        return data;
    }
   
private: 
    Data data; // or this can be pointer
    // vector<Data> multipleDatas
    
    
    // Data *myData;
    // new operator can be called in an external class -> owner is that particular class
};

#endif // DATAMODEL_H

