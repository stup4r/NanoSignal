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

#include "process.h"

Process::Process()
{

}
Process::~Process(){

}

void Process::setIsWindowed(bool isWin){
    this->isWindowed = isWin;
}

void Process::setOrder(int o){
    this->order=o;
}

void Process::setWindow(int w){
    this->windowSize = w;
}

/**
 * @brief Process::dataExtraction Extracts data from a container and links them to the helper struct.
 * @param data Data container
 * @return  QVector of DataLink helpers, each set contains a link to the single file and its corresponding filename, variance etc.
 */
QVector<DataLink> Process::dataExtraction(Data& data){

    QVector<DataLink> dataLinks;
    for (unsigned int i=0; i<data.fileNames.size(); ++i){
        DataLink datalink;
        datalink.name = &(data.fileNames[i]);
        datalink.file = &(data.defData[i]);
        datalink.varfile = &(data.varData[i]);
        dataLinks.push_back(datalink);
    }
    return dataLinks;
}

/**
 * @brief Process::doProcessMulti Triggers doProcessOne overridden methods of child classes, each in a separate thread.
 * Crucial function that allows multi-threaded processing of files usign a QtConcurrent::map).
 * It includes a QFutureWatcher to keep track of the progress and reports it back to the QProgressDialog.
 * @param data Data container.
 */
void Process::doProcessMulti(Data& data){

    QVector<DataLink> dataLinks = dataExtraction(data);

    QProgressDialog dialog;
    dialog.setWindowTitle("NanoSignal");
    dialog.setLabelText(QString("Processing..."));

    QFutureWatcher<void> watcher;

    QObject::connect(&dialog, SIGNAL(canceled()), &watcher, SLOT(cancel()));
    QObject::connect(&watcher, SIGNAL(finished()), &dialog, SLOT(reset()));
    QObject::connect(&watcher, SIGNAL(progressRangeChanged(int,int)), &dialog, SLOT(setRange(int,int)));
    QObject::connect(&watcher, SIGNAL(progressValueChanged(int)), &dialog, SLOT(setValue(int)));

    watcher.setFuture(QtConcurrent::map(dataLinks, [this] (DataLink& datalink) {doProcessOne(datalink);}));

    dialog.exec();

}
