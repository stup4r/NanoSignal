#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "types.h"
#include "data.h"
#include "reader.h"
#include "flattener.h"
#include "variance.h"
#include "plotter.h"
#include "notebook.h"
#include "fourier.h"
#include "filter.h"
#include "customplotzoom.h"
#include "manipulation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void importing(QStringList);
    void setState();
    void populateCombos(QStringList&);
    void checkInputValues(vector<vector<dataType> >&, int&);

private slots:
    void on_actionImport_triggered();

    void on_fitPreviewButton_clicked();

    void on_ApplyFlatButton_clicked();

    void on_ApplyVarButton_clicked();

    void on_actionExit_triggered();

    void on_extractPlotButton_clicked();

    void on_extractSettingsButton_clicked();

    void on_saveNotebookButton_clicked();

    void on_clearNotebookButton_clicked();

    void on_applyCutoffButton_clicked();

    void on_applyVarBarsButton_clicked();

    void on_boxPlotButton_clicked();

    void on_calcSingleFFTButton_clicked();

    void on_applyMovAvgButton_clicked();

    void on_plotButton_clicked();

    void on_filterPreviewButton_clicked();

    void on_actionAppend_triggered();

    void on_actionManipulation_triggered();

    void on_actionFlattening_triggered();

    void on_actionFiltering_triggered();

    void on_actionFFT_triggered();

    void on_actionVariance_triggered();

    void on_actionAbout_triggered();

    void on_actionManual_triggered();

private:
    Ui::MainWindow *ui;
    Data data;
    Notebook notebook;
};

#endif // MAINWINDOW_H
