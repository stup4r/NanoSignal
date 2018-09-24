/********************************************************************************
** Form generated from reading UI file 'manipulation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANIPULATION_H
#define UI_MANIPULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Manipulation
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QListWidget *listFileNames;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *lineEditSampleFreq;
    QLabel *label_4;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkSubsampling;
    QGroupBox *groupDownample;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QSpinBox *lineEditNewSampleFreq;
    QLabel *label_5;

    void setupUi(QDialog *Manipulation)
    {
        if (Manipulation->objectName().isEmpty())
            Manipulation->setObjectName(QStringLiteral("Manipulation"));
        Manipulation->resize(531, 426);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Manipulation->sizePolicy().hasHeightForWidth());
        Manipulation->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(Manipulation);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(170, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Manipulation);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 311, 351));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        listFileNames = new QListWidget(groupBox);
        listFileNames->setObjectName(QStringLiteral("listFileNames"));
        listFileNames->setDragEnabled(true);
        listFileNames->setDragDropMode(QAbstractItemView::InternalMove);

        gridLayout_2->addWidget(listFileNames, 1, 0, 1, 1);

        layoutWidget = new QWidget(Manipulation);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 40, 181, 47));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEditSampleFreq = new QSpinBox(layoutWidget);
        lineEditSampleFreq->setObjectName(QStringLiteral("lineEditSampleFreq"));
        lineEditSampleFreq->setMinimum(1);
        lineEditSampleFreq->setMaximum(10000000);
        lineEditSampleFreq->setValue(5);

        horizontalLayout_2->addWidget(lineEditSampleFreq);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(Manipulation);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(330, 120, 181, 121));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkSubsampling = new QCheckBox(layoutWidget1);
        checkSubsampling->setObjectName(QStringLiteral("checkSubsampling"));

        verticalLayout_3->addWidget(checkSubsampling);

        groupDownample = new QGroupBox(layoutWidget1);
        groupDownample->setObjectName(QStringLiteral("groupDownample"));
        gridLayout = new QGridLayout(groupDownample);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(groupDownample);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditNewSampleFreq = new QSpinBox(groupDownample);
        lineEditNewSampleFreq->setObjectName(QStringLiteral("lineEditNewSampleFreq"));
        lineEditNewSampleFreq->setMinimum(1);
        lineEditNewSampleFreq->setMaximum(10000000);
        lineEditNewSampleFreq->setValue(200);

        horizontalLayout->addWidget(lineEditNewSampleFreq);

        label_5 = new QLabel(groupDownample);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupDownample);


        retranslateUi(Manipulation);
        QObject::connect(buttonBox, SIGNAL(accepted()), Manipulation, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Manipulation, SLOT(reject()));
        QObject::connect(checkSubsampling, SIGNAL(toggled(bool)), groupDownample, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Manipulation);
    } // setupUi

    void retranslateUi(QDialog *Manipulation)
    {
        Manipulation->setWindowTitle(QApplication::translate("Manipulation", "Manipulation", nullptr));
        groupBox->setTitle(QApplication::translate("Manipulation", "File Order", nullptr));
        label->setText(QApplication::translate("Manipulation", "To change the order of imported/appended files, \n"
"please re-arrange the list below. \n"
"Drag and drop individual files for a desired order.", nullptr));
        label_2->setText(QApplication::translate("Manipulation", "Sampling Frequency:", nullptr));
        label_4->setText(QApplication::translate("Manipulation", "Hz", nullptr));
        checkSubsampling->setText(QApplication::translate("Manipulation", "Downsample on next import", nullptr));
        groupDownample->setTitle(QApplication::translate("Manipulation", "Downsample Settings", nullptr));
        label_3->setText(QApplication::translate("Manipulation", "New sampling frequency:", nullptr));
        label_5->setText(QApplication::translate("Manipulation", "Hz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Manipulation: public Ui_Manipulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANIPULATION_H
