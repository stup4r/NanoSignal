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

#include "manipulation.h"
#include "ui_manipulation.h"

Manipulation::Manipulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Manipulation)
{
    ui->setupUi(this);
    ui->groupDownample->setEnabled(false);
}

Manipulation::~Manipulation()
{
    delete ui;
}

bool Manipulation::ifOrderChanged(){
    return this->orderChanged;
}
bool Manipulation::ifDownsampling(){
    return ui->checkSubsampling->isChecked();
}
void Manipulation::setSampleFreq(int N){
    ui->lineEditSampleFreq->setValue(N);
}
int Manipulation::getSampleFreq(){
    return (ui->lineEditSampleFreq->text()).toInt();
}
int Manipulation::getNewSampleFreq(){
    return (ui->lineEditNewSampleFreq->text()).toInt();
}

/**
 * @brief Manipulation::setVecList Feeds the filenmas into the list box.
 * @param fileNames Vector containing file names.
 */
void Manipulation::setVecList(std::vector<std::string> fileNames){

    for (unsigned int i = 0; i < fileNames.size(); ++i){
        ui->listFileNames->addItem(QString::fromStdString(fileNames[i]));
    }
    this->listNames = fileNames;
}

/**
 * @brief Manipulation::getVecOrder Gets the new order of vectors, if changed.
 * Function returns new indices for vector re-ordering.
 * @return Vector of new indices that will be later used in Data class method reorderVec.
 * @see Data::reorderVec
 */
std::vector<size_t> const Manipulation::getVecOrder(){
    std::vector<size_t> newIndices;

    // Gets the new order of files
    std::vector<std::string> newOrder;
    for (int i = 0; i < ui->listFileNames->count(); ++i){
        QString s = ui->listFileNames->item(i)->text();
        newOrder.push_back(s.toStdString());
    }

    // Finds the distance between the new ordered item and the one in the old order
    for (unsigned int i = 0; i < listNames.size(); ++i){
        std::vector<std::string>::iterator it = std::find(newOrder.begin(), newOrder.end(), listNames[i]);
        size_t pos = distance(newOrder.begin(), it);
        newIndices.push_back(pos);
    }

    // If the same file is appended, it will find the distance of the first encountered file.
    // Therefore, a check to see if two elements are identical, the second one is raised up by 1
    for (unsigned int i=0; i < newIndices.size(); ++i){
        for (unsigned int j=i+1; j < newIndices.size(); ++j){
            if(newIndices[i]==newIndices[j]) ++newIndices[j];
        }
    }

    return newIndices;
}

void Manipulation::on_buttonBox_accepted()
{
    this->orderChanged = true;
}
