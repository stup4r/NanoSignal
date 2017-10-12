#ifndef SYSTEM_H
#define SYSTEM_H

#include "data.h"
#include "reader.h"
#include "flattener.h"
#include "filter.h"
#include "fourier.h"
#include "variance.h"
#include "plotter.h"

class System
{
public:
    System();
    ~System();

    void doImport(QStringList);
    void doAppend(QStringList);
    void doFlat();
    void doFilt();
    void doFFT();
    void doVar();
    void doVarCut(double);
    void doVarBars();
    void doVarBox();
    void doSubsequentialPlot(int);
    void doPlot(int, int);
    void doPreview(int, int);
    void doBarPlot();
    void doBoxPlot();

    void checkInputValue(vector<vector<dataType> >&, int&);

    void doReorder(vector<size_t>&);
    vector<string> getFileNames();
    void setParam(std::string, int);
    int getParam(std::string);
    void setPlotWidget(CustomPlotZoom*);
    std::map<std::string, int> getAllParams();

private:
    Data data;
    CustomPlotZoom* plotWidget = NULL;

};

#endif // SYSTEM_H
