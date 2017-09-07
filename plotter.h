#ifndef PLOTTER_H
#define PLOTTER_H
#include "qcustomplot.h"
#include "data.h"
#include "mainwindow.h"
#include "customplotzoom.h"

using std::vector;

class Plotter
{

public:
    //LP
    Plotter(CustomPlotZoom*, DataModel *dataModel);
    ~Plotter();

    string finePrintName(string&);
    void setMinMaxRange(dataType, dataType);
    void plotProcessPreview(vector<dataType>&, vector<dataType>&);
    void plotFFTPreview(vector<dataType>&, vector<dataType>&);
    void subsequentialPlot_Var(Data&);
    void varBarPlot();
    // LP O1 : declare the param you send in as const
    // O2: Decoupling -> move data outside mainwindow
    void varBoxPlot(vector<vector<dataType> >&, vector<string>&);
    void plotSingle(vector<dataType>&);


private:
    DataModel *dataModel; // do not own the model
    CustomPlotZoom* plot = NULL;
    dataType minRange = 0;
    dataType maxRange = 1;
};

#endif // PLOTTER_H

