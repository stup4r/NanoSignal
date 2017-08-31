#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QTextEdit>
#include "qcustomplot.h"
#include "qcpdocumentobject.h"
#include <map>
#include <string>

class Notebook
{
public:
    Notebook();
    ~Notebook();

    void setTextEdit(QTextEdit*);
    void extractPlot(QCustomPlot*, double, double);
    void extractSettings(std::map<std::string, int>&);
    void saveNotebook(QString&);
    void clearNotes();

private:
    QTextEdit* notebookTextEdit;
};

#endif // NOTEBOOK_H
