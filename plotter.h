#ifndef PLOTTER_H
#define PLOTTER_H
#include "qcustomplot.h"
#include "data.h"
#include "customplotzoom.h"

using std::vector;

/**
 * @brief The Plotter class Plotting class that takes care of all the plot generation and parsing to the plotting widget.
 */
class Plotter
{

public:

// set params as const when have time

    Plotter(CustomPlotZoom*);
    ~Plotter();

    string finePrintName(string&);
    void setMinMaxRange(dataType, dataType);

    void plotProcessPreview(vector<dataType>&, vector<dataType>&);
    void plot(vector<dataType>&, vector<dataType>&, int);
    void subsequentialPlot(Data&, int);
    void varBarPlot(Data&);
    void varBoxPlot(Data&);
    void plot(Data&, int, int);


private:

    CustomPlotZoom* plotWidget;
    dataType minRange = 0;
    dataType maxRange = 1;
};

#endif // PLOTTER_H

