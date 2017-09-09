#ifndef PLOTTER_H
#define PLOTTER_H
#include "qcustomplot.h"
#include "data.h"
#include "customplotzoom.h"

using std::vector;

class Plotter
{

public:
    //LP
    Plotter(CustomPlotZoom*);
    ~Plotter();

    string finePrintName(string&);
    void setMinMaxRange(dataType, dataType);

    void plotProcessPreview(vector<dataType>&, vector<dataType>&);
    void plot(vector<dataType>&, vector<dataType>&, int);
    void subsequentialPlot(Data&, int);
    void varBarPlot(Data&);
    // LP O1 : declare the param you send in as const
    // O2: Decoupling -> move data outside mainwindow
    void varBoxPlot(vector<vector<dataType> >&, vector<string>&);
    void plot(vector<dataType>&, int);


private:

    CustomPlotZoom* plotWidget;
    dataType minRange = 0;
    dataType maxRange = 1;
};

#endif // PLOTTER_H

