#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    DataModel dataModel;
    // DataModel *dataModel = new...
    
    MainWindow w;
    w.setDataModel(&dataModel);
    
    w.show();

    return a.exec();
}

