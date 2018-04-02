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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "types.h"
#include "data.h"
#include "notebook.h"
#include "customplotzoom.h"
#include "manipulation.h"
#include "system.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();   

    void setState();    
    void setSystem(System*);
    
private:

    void populateCombos(QStringList&);
    void checkInputValues(bool, int);

private slots:

    /**
     * Generated by Qt
     */

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

    void on_actionExtract_variance_triggered();

private:
    Ui::MainWindow *ui; /**< Main Window ui */
    System *system; /**< Pointer to the data manager object */
    Notebook notebook; /**< A notebook object */
};

#endif // MAINWINDOW_H

