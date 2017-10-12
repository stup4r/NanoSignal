#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv); /**< Application API */
    System system; /**< Data manager */
    MainWindow w; /**< Application Window */

    w.setSystem(&system);
    w.show();

    return a.exec();
}
