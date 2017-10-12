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

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QTextEdit>
#include "qcustomplot.h"
#include "qcpdocumentobject.h"
#include <map>
#include <string>

/**
 * @brief The Notebook class Notebook window class.
 * The Notebook is used to write notes and extract graphs and settings.
 * Class method names are self-explanatory.
 */
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
