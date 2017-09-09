#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    System system; // Try pointer to compare
    
    MainWindow w;

    w.setSystem(&system);
    w.show();

    return a.exec();
}
