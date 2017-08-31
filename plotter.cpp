#include "plotter.h"

Plotter::Plotter(CustomPlotZoom* externalPlot)
{
    plot = externalPlot;
    plot->setZoomMode(true);
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
    plot->clearGraphs();
    plot->clearPlottables();
    plot->xAxis->setTickLabels(true);

    QVector<double> x1(v1.size());
    iota(x1.begin(), x1.end(), 0);
    QVector<double> x2(v2.size());
    iota(x2.begin(), x2.end(), 0);

    QVector<double> y1 = QVector<double>::fromStdVector(v1);
    QVector<double> y2 = QVector<double>::fromStdVector(v2);

    plot->addGraph();
    plot->graph(0)->setData(x1, y1);
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->graph(0)->setName("Raw File");
    plot->graph(0)->rescaleAxes(true);
    plot->addGraph();
    plot->graph(1)->setData(x2, y2);
    plot->graph(1)->setPen(QPen(Qt::red));
    plot->graph(1)->setName("Processed File");
    plot->graph(1)->rescaleAxes(true);

    plot->legend->setVisible(true);
    plot->xAxis->setLabel("Time [points]");
    plot->yAxis->setLabel("Deflection");
    plot->rescaleAxes();
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);
    plot->replot();
}

void Plotter::plotFFTPreview(vector<dataType>& freq, vector<dataType>& z){
    plot->clearGraphs();
    plot->clearPlottables();
    plot->xAxis->setTickLabels(true);

    QVector<double> x = QVector<double>::fromStdVector(freq);
    QVector<double> y = QVector<double>::fromStdVector(z);

    plot->addGraph();
    plot->graph(0)->setData(x, y);
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->xAxis->setRange(minRange, maxRange);
    plot->yAxis->setRange(minRange, 10*z[maxRange/2]);
    plot->legend->setVisible(false);
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);
    plot->xAxis->setLabel("Frequency [Hz]");
    plot->yAxis->setLabel("Power");
    plot->replot();
}

void Plotter::subsequentialPlot_Var(Data& data){
    plot->clearGraphs();
    plot->clearPlottables();
    plot->xAxis->setTickLabels(true);
    QPen pen;
    pen.setWidth(2);
    int step=2;
    int len = 0;
    for (unsigned int i=0; i<data.varData.size(); ++i){
        plot->addGraph();
        plot->graph()->setName(QString::fromStdString(finePrintName(data.fileNames[i])));
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
        plot->graph()->setData(QvecX, QvecY);
        plot->xAxis->setLabel("Time [minutes]");
        plot->yAxis->setLabel("Variance [a.u.]");
        plot->graph()->rescaleAxes(true);
        plot->graph()->setPen(pen);
    }
    plot->rescaleAxes();
    plot->legend->setVisible(true);
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);
    //ui->plot->setOpenGl(true);
    plot->replot();
}

void Plotter::varBarPlot(Data& data){
    plot->xAxis->setTickLabels(true);
    plot->clearGraphs();
    plot->clearPlottables();
    int step=2;
    int len=1;

    for (unsigned int i = 0; i < (data.varMeans.size())/2; ++i){

        QCPBars *bars = new QCPBars(plot->xAxis, plot->yAxis);
        QCPErrorBars *errorBars = new QCPErrorBars(plot->xAxis, plot->yAxis);
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
    plot->legend->setVisible(true);
    plot->rescaleAxes();
    plot->xAxis->setLabel("File Sections");
    plot->yAxis->setLabel("Mean Variance");
    plot->replot();
}

void Plotter::varBoxPlot(vector<vector<dataType> >& stat, vector<string>& fileNames){

    plot->clearGraphs();
    plot->clearPlottables();

    QCPStatisticalBox *statistical = new QCPStatisticalBox(plot->xAxis, plot->yAxis);
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
    plot->xAxis->setTickLabels(true);
    plot->legend->setVisible(false);
    plot->xAxis->setLabel("File");
    plot->yAxis->setLabel("Variance");
    plot->xAxis->setTickLabelRotation(20);
    plot->xAxis->setTicker(textTicker);
    plot->rescaleAxes();
    plot->replot();
}

void Plotter::plotSingle(vector<dataType>& v){
    plot->clearGraphs();
    plot->clearPlottables();
    plot->xAxis->setTickLabels(true);

    QVector<double> x(v.size());
    iota(x.begin(), x.end(), 0);

    QVector<double> y = QVector<double>::fromStdVector(v);

    plot->addGraph();
    plot->graph(0)->setData(x, y);
    plot->graph(0)->setPen(QPen(Qt::blue));
    plot->graph(0)->rescaleAxes(true);

    plot->legend->setVisible(false);
    plot->xAxis->setLabel("Sample Points");
    plot->yAxis->setLabel("Chosen Data");
    plot->rescaleAxes();
    plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                          QCP::iSelectLegend | QCP::iSelectPlottables);
    plot->replot();
}
