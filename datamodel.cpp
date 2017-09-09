#include "dataModel.h"

DataModel::DataModel(){

}
DataModel::~DataModel(){

}

void DataModel::importing(QStringList fileNames){
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

    Reader * reader = new Reader;
    reader->setIsDownsampled(data.parameters["isDownsampled"]);
    reader->setDownSamplingStep(data.parameters["downSamplingFreq"]);
    reader->doProcessMulti(this->data);
    delete reader;
    data.parameters["isDownsampled"] = 0;
}

void DataModel::appending(QStringList fileNames){
    // Convert QStringList into vector<string>
    std::vector<string> fileNamesVec;
    for (int i = 0; i < fileNames.size(); ++i) {
        std::string tmp = fileNames[i].toStdString();
        fileNamesVec.push_back(tmp);
    }

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
