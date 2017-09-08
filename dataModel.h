// LP

#ifndef DATAMODEL_H
#define DATAMODEL_H

class DataModel {
public:
    DataModel(); // init and data
    ~DataModel();
    
    void importing();
    
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

