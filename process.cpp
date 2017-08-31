#include "process.h"

Process::Process()
{

}
Process::~Process(){

}

void Process::setIsWindowed(bool isWin){
    this->isWindowed = isWin;
}

void Process::setOrder(int o){
    this->order=o;
}

void Process::setWindow(int w){
    this->windowSize = w;
}

QVector<DataLink> Process::dataExtraction(Data& data){

    QVector<DataLink> dataLinks;
    for (unsigned int i=0; i<data.fileNames.size(); ++i){
        DataLink datalink;
        datalink.name = &(data.fileNames[i]);
        datalink.file = &(data.defData[i]);
        datalink.varfile = &(data.varData[i]);
        dataLinks.push_back(datalink);
    }
    return dataLinks;
}

void Process::doProcessMulti(Data& data){

    QVector<DataLink> dataLinks = dataExtraction(data);

    QProgressDialog dialog;
    dialog.setWindowTitle("NanoSignal");
    dialog.setLabelText(QString("Processing..."));

    QFutureWatcher<void> watcher;

    QObject::connect(&dialog, SIGNAL(canceled()), &watcher, SLOT(cancel()));
    QObject::connect(&watcher, SIGNAL(finished()), &dialog, SLOT(reset()));
    QObject::connect(&watcher, SIGNAL(progressRangeChanged(int,int)), &dialog, SLOT(setRange(int,int)));
    QObject::connect(&watcher, SIGNAL(progressValueChanged(int)), &dialog, SLOT(setValue(int)));

    watcher.setFuture(QtConcurrent::map(dataLinks, [this] (DataLink& datalink) {doProcessOne(datalink);}));

    dialog.exec();

}
