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

void Manipulation::setVecList(std::vector<std::string> fileNames){

    for (unsigned int i = 0; i < fileNames.size(); ++i){
        ui->listFileNames->addItem(QString::fromStdString(fileNames[i]));
    }
    this->listNames = fileNames;
}

std::vector<size_t> const Manipulation::getVecOrder(){
    std::vector<size_t> newIndices;

    std::vector<std::string> newOrder;
    for (int i = 0; i < ui->listFileNames->count(); ++i){
        QString s = ui->listFileNames->item(i)->text();
        newOrder.push_back(s.toStdString());
    }

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
