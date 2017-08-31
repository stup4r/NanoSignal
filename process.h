#ifndef PROCESS_H
#define PROCESS_H

#include "data.h"
#include<QtConcurrent/QtConcurrentRun>
#include<QtConcurrent/QtConcurrentMap>
#include<QProgressDialog>
#include<QFutureWatcher>

/*! \brief A struct with members linked to data elements */

struct DataLink{
    string* name;
    vector<dataType>* file;
    vector<dataType>* varfile;
    vector<dataType>* fftfile;
};

/*! \brief An abstract class, used as a parent for other classes */

class Process
{
public:
    Process();
    virtual ~Process(); /*!< Virtual destuctor to preserve order of instantiation and destruction of child classes */

    virtual void doProcessOne(DataLink&)=0; /*!< Pure virtual function to be overloaded in derived classes */
    void doProcessMulti(Data&);

    QVector<DataLink> dataExtraction(Data&);
    void setIsWindowed(bool);
    void setOrder(int);
    void setWindow(int);

protected:
    bool isWindowed = false; /*!< Boolean value controlling if window is applied */
    int order = 1; /*!< Order used for polynomial fitting */
    int windowSize = 10; /*!< Size of a window for various processing steps */
};

#endif // PROCESS_H
