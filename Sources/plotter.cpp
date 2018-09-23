/*************************************************************************
 *
 *  NanoSignal: Signal analysis toolbox.
 *  Copyright (C) 2017  Petar Stupar
 *  Collective Copyright Holder.
 *  Licensed under the GPLv3.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ************************************************************************/

#include "plotter.h"

Plotter::Plotter(CustomPlotZoom* externalPlot)
{
    plotWidget = externalPlot;
    plotWidget->setZoomMode(true);
}

Plotter::~Plotter(){

}

/**
 * @brief Plotter::finePrintName Removes the path from the filename, for clarity.
 * @param fileName Filename string
 * @return The same filename string, but stipped off the path.
 */
string Plotter::finePrintName(string& fileName){

    size_t found = fileName.find_last_of("/\\");
    string finePrint = fileName.substr(found+1);

    return finePrint;
}

void Plotter::setMinMaxRange(dataType min, dataType max){
    this->minRange = min;
    this->maxRange = max;
}

/**
 * @brief Plotter::plotProcessPreview Plots the comparison between the raw file and a preview of the selected processing.
 * @param v1 Raw file
 * @param v2 Processing preview
 */
void Plotter::plotProcessPreview(vector<dataType>& v1, vector<dataType>& v2){
    plotWidget->clearGraphs();
    plotWidget->clearPlottables();
    plotWidget->xAxis->setTickLabels(true);

    QVector<double> x1(v1.size());
    iota(x1.begin(), x1.end(), 0);
    QVector<double> x2(v2.size());
    iota(x2.begin(), x2.end(), 0);

    QVector<double> y1 = QVector<double>::fromStdVector(v1);
    QVector<double> y2 = QVector<double>::fromStdVector(v2);

    plotWidget->addGraph();
    plotWidget->graph(0)->setData(x1, y1);
    plotWidget->graph(0)->setPen(QPen(Qt::blue));
    plotWidget->graph(0)->setName("Raw File");
    plotWidget->graph(0)->rescaleAxes(true);
    plotWidget->addGraph();
    plotWidget->graph(1)->setData(x2, y2);
    plotWidget->graph(1)->setPen(QPen(Qt::red));
    plotWidget->graph(1)->setName("Processed File");
    plotWidget->graph(1)->rescaleAxes(true);

    plotWidget->legend->setVisible(true);
    plotWidget->xAxis->setLabel("Time [points]");
    plotWidget->yAxis->setLabel("Deflection");
    plotWidget->rescaleAxes();
    plotWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);
    plotWidget->replot();
}

/**
 * @brief Plotter::plot Plots the data, and sets the label depending on the int s.
 * @param vecX X vector to plot.
 * @param vecY Y vector to plot.
 * @param s label case: 0 is the deflection, 2 is the FFT
 */
void Plotter::plot(vector<dataType>& vecX, vector<dataType>& vecY, int s){
    plotWidget->clearGraphs();
    plotWidget->clearPlottables();
    plotWidget->xAxis->setTickLabels(true);

    QVector<double> x = QVector<double>::fromStdVector(vecX);
    QVector<double> y = QVector<double>::fromStdVector(vecY);

    plotWidget->addGraph();
    plotWidget->graph(0)->setData(x, y);
    plotWidget->graph(0)->setPen(QPen(Qt::blue));

    switch (s) {
    case 0:
        plotWidget->xAxis->setLabel("Time [Sample Points]");
        plotWidget->yAxis->setLabel("Deflection [a.u.]");
        break;
    case 1:
        break;
    case 2:
        plotWidget->xAxis->setRange(minRange, maxRange);
        plotWidget->yAxis->setRange(minRange, 10*vecY[maxRange/2]);
        plotWidget->xAxis->setLabel("Frequency [Hz]");
        plotWidget->yAxis->setLabel("Power");
        break;

    default:
        break;
    }

    plotWidget->legend->setVisible(false);
    plotWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);

    plotWidget->replot();
}

/**
 * @brief Plotter::subsequentialPlot Plots files one after the other in a single plot.
 * @param data Data container to extract the right files, depending on the int s.
 * @param s Swich statement modifier: 3 is the variance plot.
 * Due to the fact that large files are imported, I will think about not implementing the subsequential plot of deflection data.
 */
void Plotter::subsequentialPlot(Data& data, int s){
    plotWidget->clearGraphs();
    plotWidget->clearPlottables();
    plotWidget->xAxis->setTickLabels(true);
    switch (s) {
    case 0:
    case 1:
        break;
    case 2:
        break;
    case 3:{
        QPen pen;
        pen.setWidth(2);
        int step=2;
        int len = 0;
        for (unsigned int i=0; i<data.varData.size(); ++i){
            plotWidget->addGraph();
            plotWidget->graph()->setName(QString::fromStdString(finePrintName(data.fileNames[i])));
            pen.setColor(QColor(qSin(step*0.3)*100+100, qSin(step*0.6+0.7)*100+100, qSin(step*0.4+0.6)*100+100));
            step = step * step;
            vector<dataType> Xvec(data.varData[i].size());
            iota(Xvec.begin(), Xvec.end(), len);
            len += data.varData[i].size();
            for(unsigned int k=0;k<Xvec.size();++k){
                Xvec[k]=Xvec[k]*data.parameters["varWin"]/(60*data.parameters["samplingFreq"]);
            }
            QVector<double> QvecY = QVector<double>::fromStdVector(data.varData[i]);
            QVector<double> QvecX = QVector<double>::fromStdVector(Xvec);
            Xvec.clear();
            plotWidget->graph()->setData(QvecX, QvecY);
            plotWidget->xAxis->setLabel("Time [minutes]");
            plotWidget->yAxis->setLabel("Variance [a.u.]");
            plotWidget->graph()->rescaleAxes(true);
            plotWidget->graph()->setPen(pen);
        }
        break;
    }
    default:
        break;
    }

    plotWidget->rescaleAxes();
    plotWidget->legend->setVisible(true);
    plotWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);
    //ui->plotWidget->setOpenGl(true);
    plotWidget->replot();
}

/**
 * @brief Plotter::varBarPlot Plots variance averages as bars.
 * @param data Data container to extract variance means.
 */
void Plotter::varBarPlot(Data& data){
    plotWidget->xAxis->setTickLabels(true);
    plotWidget->clearGraphs();
    plotWidget->clearPlottables();
    int step=2;
    int len=1;

    for (unsigned int i = 0; i < (data.varMeans.size())/2; ++i){

        QCPBars *bars = new QCPBars(plotWidget->xAxis, plotWidget->yAxis);
        QCPErrorBars *errorBars = new QCPErrorBars(plotWidget->xAxis, plotWidget->yAxis);
        errorBars->removeFromLegend();
        errorBars->setAntialiased(false);
        QPen pen(QColor(130, 130, 130));
        pen.setWidth(2);
        errorBars->setPen(pen);

        vector<double> x(data.varMeans[2*i].size());
        iota(x.begin(), x.end(), len);
        len += data.varMeans[2*i].size();
        QVector<double> QvecY = QVector<double>::fromStdVector(data.varMeans[2*i]);
        QVector<double> QvecX = QVector<double>::fromStdVector(x);

        // Try to delete Qvectors after adding them to plot!
        bars->setData(QvecX, QvecY);
        bars->setName(QString::fromStdString(finePrintName(data.fileNames[i])));
        bars->setPen(Qt::NoPen);
        bars->setBrush(QColor(qSin(step*0.3)*100+100, qSin(step*0.6+0.7)*100+100, qSin(step*0.4+0.6)*100+100));
        step = step * step;
        errorBars->setDataPlottable(bars);
        QVector<double> QerrVec = QVector<double>::fromStdVector(data.varMeans[2*i+1]);
        errorBars->setData(QerrVec);
    }
    plotWidget->legend->setVisible(true);
    plotWidget->rescaleAxes();
    plotWidget->xAxis->setLabel("File Sections");
    plotWidget->yAxis->setLabel("Mean Variance");
    plotWidget->replot();
}

/**
 * @brief Plotter::varBoxPlot Creates a box plot by using data from the data container.
 * @param data Data container from which statistics are extracted (data.statistic).
 */
void Plotter::varBoxPlot(Data& data){

    plotWidget->clearGraphs();
    plotWidget->clearPlottables();

    QCPStatisticalBox *statistical = new QCPStatisticalBox(plotWidget->xAxis, plotWidget->yAxis);
    QBrush boxBrush(QColor(60, 60, 255, 100));
    boxBrush.setStyle(Qt::Dense6Pattern);
    statistical->setBrush(boxBrush);

    for (unsigned int i = 0; i< data.statistic.size()/2; ++i){
        double qKey = i;
        QVector<double> Qoutlier = QVector<double>::fromStdVector(data.statistic[2*i+1]);
        statistical->addData(qKey, data.statistic[2*i][0], data.statistic[2*i][1], data.statistic[2*i][2], data.statistic[2*i][3], data.statistic[2*i][4], Qoutlier);
    }

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (unsigned int i = 0; i < data.fileNames.size(); ++i){
        textTicker->addTick(i, QString::fromStdString(finePrintName(data.fileNames[i])));
    }
    plotWidget->xAxis->setTickLabels(true);
    plotWidget->legend->setVisible(false);
    plotWidget->xAxis->setLabel("File");
    plotWidget->yAxis->setLabel("Variance");
    plotWidget->xAxis->setTickLabelRotation(20);
    plotWidget->xAxis->setTicker(textTicker);
    plotWidget->rescaleAxes();
    plotWidget->replot();
}

/**
 * @brief Plotter::plot Regular plot of a single file, depening on the int s.
 * @param data Data container from which files are extracted.
 * @param fileIndex Index of the data vectors pointing to the chosen file (filename).
 * @param s Switch case modifier: 0 and 1 - deflection data, 2 - FFT, 3 - variance.
 */
void Plotter::plot(Data& data, int fileIndex, int s){
    plotWidget->clearGraphs();
    plotWidget->clearPlottables();
    plotWidget->xAxis->setTickLabels(true);

    plotWidget->addGraph();
    plotWidget->graph(0)->setPen(QPen(Qt::blue));
    plotWidget->graph(0)->rescaleAxes(true);
    plotWidget->graph(0)->setName(QString::fromStdString(finePrintName(data.fileNames[fileIndex])));

    int FS = data.parameters["samplingFreq"];

    switch (s) {
    case 0:
    case 1: // DEF
    {
        QVector<double> x(data.defData[fileIndex].size());
        iota(x.begin(), x.end(), 0);
        for_each(x.begin(), x.end(), [FS](dataType &i){i = i/(FS*60);});
        QVector<double> y = QVector<double>::fromStdVector(data.defData[fileIndex]);
        plotWidget->graph(0)->setData(x, y);
        plotWidget->xAxis->setLabel("Time [minutes]");
        plotWidget->yAxis->setLabel("Deflection [a.u.]");
        break;
    }
    case 2: // FFT
    {
        break;
    }
    case 3: // VAR
    {
        int varWin = data.parameters["varWin"];
        QVector<double> x(data.varData[fileIndex].size());
        iota(x.begin(), x.end(), 0);
        for_each(x.begin(), x.end(), [varWin, FS](dataType &i){i = i*varWin/(FS*60);});
        QVector<double> y = QVector<double>::fromStdVector(data.varData[fileIndex]);
        plotWidget->graph(0)->setData(x, y);
        plotWidget->xAxis->setLabel("Time [minutes]");
        plotWidget->yAxis->setLabel("Deflection [a.u.]");
        break;
    }
    default:
        break;
    }

    plotWidget->legend->setVisible(true);
    plotWidget->rescaleAxes();
    plotWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);
    plotWidget->replot();
}
