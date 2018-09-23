#ifndef TESTCLASS_H
#define TESTCLASS_H
#include "mainwindow.h"
#include "qcpdocumentobject.h"

#include <QTextEdit>
class testClass
{
public:
    testClass(QMainWindow*);
    ~testClass();

    void doSome();
};

#endif // TESTCLASS_H
