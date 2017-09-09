#include "plotter.h"

Plotter::Plotter(CustomPlotZoom* externalPlot)
{
    plotWidget = externalPlot;
    plotWidget->setZoomMode(true);
}

Plotter::~Plotter(){

}

string Plotter::finePrintName(string& fileName){

    size_t found = fileName.find_last_of("/\\");
    string finePrint = fileName.substr(found+1);

    return finePrint;
}

void Plotter::setMinMaxRange(dataType min, dataType max){
    this->minRange = min;
    this->maxRange = max;
}

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

void Plotter::subsequentialPlot(Data& data, int s){
    plotWidget->clearGraphs();
    plotWidget->clearPlottables();
    plotWidget->xAxis->setTickLabels(true);
    switch (s) {
    case 0:
        break;
    case 1:{
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
    }
        break;
    case 2:
        break;
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

void Plotter::varBoxPlot(vector<vector<dataType> >& stat, vector<string>& fileNames){

    plotWidget->clearGraphs();
    plotWidget->clearPlottables();

    QCPStatisticalBox *statistical = new QCPStatisticalBox(plotWidget->xAxis, plotWidget->yAxis);
    QBrush boxBrush(QColor(60, 60, 255, 100));
    boxBrush.setStyle(Qt::Dense6Pattern);
    statistical->setBrush(boxBrush);

    for (unsigned int i = 0; i< stat.size()/2; ++i){
        double qKey = i;
        QVector<double> Qoutlier = QVector<double>::fromStdVector(stat[2*i+1]);
        statistical->addData(qKey, stat[2*i][0], stat[2*i][1], stat[2*i][2], stat[2*i][3], stat[2*i][4], Qoutlier);
    }

    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    for (unsigned int i = 0; i < fileNames.size(); ++i){
        textTicker->addTick(i, QString::fromStdString(finePrintName(fileNames[i])));
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

void Plotter::plot(vector<dataType>& v, int s){
    plotWidget->clearGraphs();
    plotWidget->clearPlottables();
    plotWidget->xAxis->setTickLabels(true);

    QVector<double> x(v.size());
    iota(x.begin(), x.end(), 0);

    QVector<double> y = QVector<double>::fromStdVector(v);

    plotWidget->addGraph();
    plotWidget->graph(0)->setData(x, y);
    plotWidget->graph(0)->setPen(QPen(Qt::blue));
    plotWidget->graph(0)->rescaleAxes(true);

    plotWidget->legend->setVisible(false);
    switch (s) {
    case 0:
        plotWidget->xAxis->setLabel("Time [Sample Points]");
        plotWidget->yAxis->setLabel("Deflection [a.u.]");
        break;
    case 1:
        plotWidget->xAxis->setLabel("Time [Sample Points]");
        plotWidget->yAxis->setLabel("Variance [a.u.]");
        break;
    case 2:
        break;
    default:
        break;
    }

    plotWidget->rescaleAxes();
    plotWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);
    plotWidget->replot();
}
