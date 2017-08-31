#ifndef MANIPULATION_H
#define MANIPULATION_H

#include <QDialog>
#include <vector>
#include <string>

namespace Ui {
class Manipulation;
}

class Manipulation : public QDialog
{
    Q_OBJECT

public:
    explicit Manipulation(QWidget *parent = 0);
    ~Manipulation();

    std::vector<size_t> const getVecOrder();
    void setVecList(std::vector<std::string>);
    bool ifOrderChanged();
    bool ifDownsampling();
    void setSampleFreq(int);
    int getSampleFreq();
    int getNewSampleFreq();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Manipulation *ui;
    std::vector<std::string> listNames;
    bool orderChanged = false;
};

#endif // MANIPULATION_H
