/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <customplotzoom.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionImport;
    QAction *actionFast_Import;
    QAction *actionExit;
    QAction *actionAppend;
    QAction *actionManipulation;
    QAction *actionPlot_Settings;
    QAction *actionNotebook;
    QAction *actionFlattening;
    QAction *actionFiltering;
    QAction *actionFFT;
    QAction *actionVariance;
    QAction *actionManual;
    QAction *actionAbout;
    QAction *actionExtract_variance;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QTabWidget *processBox;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *isWindowedCheck;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *flatWinEdit;
    QComboBox *unitsFlatWin;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QSpinBox *flatOrderEdit;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QComboBox *fitPreviewCombo;
    QPushButton *fitPreviewButton;
    QPushButton *ApplyFlatButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_23;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_21;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QSpinBox *editMovAvgWin;
    QComboBox *unitsFiltWin;
    QGroupBox *groupBox_13;
    QGridLayout *gridLayout_22;
    QLabel *label_14;
    QPushButton *filterPreviewButton;
    QComboBox *comboFiltPreviewFiles;
    QPushButton *applyMovAvgButton;
    QWidget *tab_4;
    QGridLayout *gridLayout_20;
    QGridLayout *gridLayout_19;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_18;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QSpinBox *editSamplingFreq;
    QLabel *label_12;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_17;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_9;
    QComboBox *comboFFTfiles;
    QPushButton *calcSingleFFTButton;
    QPushButton *applyFFTbutton;
    QWidget *tab_3;
    QGridLayout *gridLayout_15;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *varWinEdit;
    QComboBox *unitsVarWin;
    QPushButton *ApplyVarButton;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpinBox *barSizeEdit;
    QComboBox *unitsVarBar;
    QPushButton *applyVarBarsButton;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_14;
    QLabel *label_7;
    QPushButton *applyCutoffButton;
    QDoubleSpinBox *editCutoffVar;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_16;
    QLabel *label_8;
    QPushButton *boxPlotButton;
    QWidget *widget;
    QGridLayout *gridLayout_13;
    QPushButton *notebookButton;
    QPushButton *plotstngsButton;
    QWidget *widgetNotebook;
    QGridLayout *gridLayout_9;
    QPushButton *extractSettingsButton;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_12;
    QVBoxLayout *verticalLayout_7;
    QSpinBox *spinBoxWidth;
    QSpinBox *spinBoxHeight;
    QPushButton *saveNotebookButton;
    QPushButton *clearNotebookButton;
    QPushButton *extractPlotButton;
    QTextEdit *notebookTextEdit;
    QSpacerItem *verticalSpacer_2;
    QWidget *widgetPlotSettings;
    QGridLayout *gridLayout_11;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *radioAllFiles;
    QComboBox *comboPlotType;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *radioSignleFile;
    QComboBox *comboPlotSettingsFiles;
    QPushButton *plotButton;
    CustomPlotZoom *plot;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuAnalysis;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(923, 855);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/icons/Icons/import.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport->setIcon(icon);
        actionFast_Import = new QAction(MainWindow);
        actionFast_Import->setObjectName(QStringLiteral("actionFast_Import"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/icons/Icons/fastimport.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFast_Import->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/icons/Icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionAppend = new QAction(MainWindow);
        actionAppend->setObjectName(QStringLiteral("actionAppend"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/icons/Icons/append.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAppend->setIcon(icon3);
        actionManipulation = new QAction(MainWindow);
        actionManipulation->setObjectName(QStringLiteral("actionManipulation"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/icons/Icons/manipulate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManipulation->setIcon(icon4);
        actionPlot_Settings = new QAction(MainWindow);
        actionPlot_Settings->setObjectName(QStringLiteral("actionPlot_Settings"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/icons/Icons/plotSettings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlot_Settings->setIcon(icon5);
        actionNotebook = new QAction(MainWindow);
        actionNotebook->setObjectName(QStringLiteral("actionNotebook"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/icons/Icons/notebook.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNotebook->setIcon(icon6);
        actionFlattening = new QAction(MainWindow);
        actionFlattening->setObjectName(QStringLiteral("actionFlattening"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/icons/Icons/flat.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFlattening->setIcon(icon7);
        actionFiltering = new QAction(MainWindow);
        actionFiltering->setObjectName(QStringLiteral("actionFiltering"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/new/icons/Icons/filt.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFiltering->setIcon(icon8);
        actionFFT = new QAction(MainWindow);
        actionFFT->setObjectName(QStringLiteral("actionFFT"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/new/icons/Icons/fft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFFT->setIcon(icon9);
        actionVariance = new QAction(MainWindow);
        actionVariance->setObjectName(QStringLiteral("actionVariance"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/new/icons/Icons/var.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVariance->setIcon(icon10);
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/new/icons/Icons/manual.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionManual->setIcon(icon11);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/new/icons/Icons/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon12);
        actionExtract_variance = new QAction(MainWindow);
        actionExtract_variance->setObjectName(QStringLiteral("actionExtract_variance"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        processBox = new QTabWidget(centralWidget);
        processBox->setObjectName(QStringLiteral("processBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(processBox->sizePolicy().hasHeightForWidth());
        processBox->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        isWindowedCheck = new QCheckBox(groupBox);
        isWindowedCheck->setObjectName(QStringLiteral("isWindowedCheck"));
        isWindowedCheck->setChecked(true);

        gridLayout_2->addWidget(isWindowedCheck, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        flatWinEdit = new QSpinBox(groupBox);
        flatWinEdit->setObjectName(QStringLiteral("flatWinEdit"));
        flatWinEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        flatWinEdit->setMinimum(1);
        flatWinEdit->setMaximum(1000000000);
        flatWinEdit->setValue(400000);

        horizontalLayout->addWidget(flatWinEdit);

        unitsFlatWin = new QComboBox(groupBox);
        unitsFlatWin->addItem(QString());
        unitsFlatWin->addItem(QString());
        unitsFlatWin->setObjectName(QStringLiteral("unitsFlatWin"));

        horizontalLayout->addWidget(unitsFlatWin);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        flatOrderEdit = new QSpinBox(groupBox_2);
        flatOrderEdit->setObjectName(QStringLiteral("flatOrderEdit"));
        flatOrderEdit->setMinimum(1);
        flatOrderEdit->setMaximum(20);
        flatOrderEdit->setValue(1);

        gridLayout->addWidget(flatOrderEdit, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        fitPreviewCombo = new QComboBox(groupBox_3);
        fitPreviewCombo->setObjectName(QStringLiteral("fitPreviewCombo"));

        verticalLayout_2->addWidget(fitPreviewCombo);


        horizontalLayout_3->addLayout(verticalLayout_2);

        fitPreviewButton = new QPushButton(groupBox_3);
        fitPreviewButton->setObjectName(QStringLiteral("fitPreviewButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fitPreviewButton->sizePolicy().hasHeightForWidth());
        fitPreviewButton->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(fitPreviewButton);


        gridLayout_6->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        ApplyFlatButton = new QPushButton(tab);
        ApplyFlatButton->setObjectName(QStringLiteral("ApplyFlatButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ApplyFlatButton->sizePolicy().hasHeightForWidth());
        ApplyFlatButton->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(ApplyFlatButton);


        gridLayout_5->addLayout(verticalLayout, 0, 0, 1, 1);

        processBox->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_23 = new QGridLayout(tab_2);
        gridLayout_23->setSpacing(6);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        groupBox_12 = new QGroupBox(tab_2);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        gridLayout_21 = new QGridLayout(groupBox_12);
        gridLayout_21->setSpacing(6);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(groupBox_12);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_10->addWidget(label_13);

        editMovAvgWin = new QSpinBox(groupBox_12);
        editMovAvgWin->setObjectName(QStringLiteral("editMovAvgWin"));
        editMovAvgWin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        editMovAvgWin->setMinimum(1);
        editMovAvgWin->setMaximum(1000000000);
        editMovAvgWin->setValue(40000);

        horizontalLayout_10->addWidget(editMovAvgWin);

        unitsFiltWin = new QComboBox(groupBox_12);
        unitsFiltWin->addItem(QString());
        unitsFiltWin->addItem(QString());
        unitsFiltWin->setObjectName(QStringLiteral("unitsFiltWin"));

        horizontalLayout_10->addWidget(unitsFiltWin);


        gridLayout_21->addLayout(horizontalLayout_10, 0, 0, 1, 1);


        gridLayout_23->addWidget(groupBox_12, 0, 0, 1, 1);

        groupBox_13 = new QGroupBox(tab_2);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        gridLayout_22 = new QGridLayout(groupBox_13);
        gridLayout_22->setSpacing(6);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        label_14 = new QLabel(groupBox_13);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_22->addWidget(label_14, 0, 0, 1, 1);

        filterPreviewButton = new QPushButton(groupBox_13);
        filterPreviewButton->setObjectName(QStringLiteral("filterPreviewButton"));
        sizePolicy2.setHeightForWidth(filterPreviewButton->sizePolicy().hasHeightForWidth());
        filterPreviewButton->setSizePolicy(sizePolicy2);

        gridLayout_22->addWidget(filterPreviewButton, 0, 1, 2, 1);

        comboFiltPreviewFiles = new QComboBox(groupBox_13);
        comboFiltPreviewFiles->setObjectName(QStringLiteral("comboFiltPreviewFiles"));

        gridLayout_22->addWidget(comboFiltPreviewFiles, 1, 0, 1, 1);


        gridLayout_23->addWidget(groupBox_13, 1, 0, 1, 1);

        applyMovAvgButton = new QPushButton(tab_2);
        applyMovAvgButton->setObjectName(QStringLiteral("applyMovAvgButton"));

        gridLayout_23->addWidget(applyMovAvgButton, 2, 0, 1, 1);

        processBox->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_20 = new QGridLayout(tab_4);
        gridLayout_20->setSpacing(6);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        gridLayout_19 = new QGridLayout();
        gridLayout_19->setSpacing(6);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        groupBox_11 = new QGroupBox(tab_4);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        gridLayout_18 = new QGridLayout(groupBox_11);
        gridLayout_18->setSpacing(6);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_10 = new QLabel(groupBox_11);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_9->addWidget(label_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(groupBox_11);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_9->addWidget(label_11);

        editSamplingFreq = new QSpinBox(groupBox_11);
        editSamplingFreq->setObjectName(QStringLiteral("editSamplingFreq"));
        editSamplingFreq->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        editSamplingFreq->setMinimum(1);
        editSamplingFreq->setMaximum(1000000000);
        editSamplingFreq->setValue(20000);

        horizontalLayout_9->addWidget(editSamplingFreq);

        label_12 = new QLabel(groupBox_11);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(12777198, 16777215));

        horizontalLayout_9->addWidget(label_12);


        verticalLayout_9->addLayout(horizontalLayout_9);


        gridLayout_18->addLayout(verticalLayout_9, 0, 0, 1, 1);


        gridLayout_19->addWidget(groupBox_11, 0, 0, 1, 1);

        groupBox_10 = new QGroupBox(tab_4);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_17 = new QGridLayout(groupBox_10);
        gridLayout_17->setSpacing(6);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_9 = new QLabel(groupBox_10);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_8->addWidget(label_9);

        comboFFTfiles = new QComboBox(groupBox_10);
        comboFFTfiles->setObjectName(QStringLiteral("comboFFTfiles"));

        verticalLayout_8->addWidget(comboFFTfiles);


        horizontalLayout_8->addLayout(verticalLayout_8);

        calcSingleFFTButton = new QPushButton(groupBox_10);
        calcSingleFFTButton->setObjectName(QStringLiteral("calcSingleFFTButton"));
        sizePolicy2.setHeightForWidth(calcSingleFFTButton->sizePolicy().hasHeightForWidth());
        calcSingleFFTButton->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(calcSingleFFTButton);


        gridLayout_17->addLayout(horizontalLayout_8, 0, 0, 1, 1);


        gridLayout_19->addWidget(groupBox_10, 1, 0, 1, 1);

        applyFFTbutton = new QPushButton(tab_4);
        applyFFTbutton->setObjectName(QStringLiteral("applyFFTbutton"));

        gridLayout_19->addWidget(applyFFTbutton, 2, 0, 1, 1);


        gridLayout_20->addLayout(gridLayout_19, 0, 0, 1, 1);

        processBox->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_15 = new QGridLayout(tab_3);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_7 = new QGridLayout(groupBox_4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        varWinEdit = new QSpinBox(groupBox_4);
        varWinEdit->setObjectName(QStringLiteral("varWinEdit"));
        varWinEdit->setMinimum(1);
        varWinEdit->setMaximum(1000000000);
        varWinEdit->setValue(200000);

        horizontalLayout_4->addWidget(varWinEdit);

        unitsVarWin = new QComboBox(groupBox_4);
        unitsVarWin->addItem(QString());
        unitsVarWin->addItem(QString());
        unitsVarWin->setObjectName(QStringLiteral("unitsVarWin"));

        horizontalLayout_4->addWidget(unitsVarWin);


        verticalLayout_3->addLayout(horizontalLayout_4);

        ApplyVarButton = new QPushButton(groupBox_4);
        ApplyVarButton->setObjectName(QStringLiteral("ApplyVarButton"));

        verticalLayout_3->addWidget(ApplyVarButton);


        gridLayout_7->addLayout(verticalLayout_3, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_8 = new QGridLayout(groupBox_5);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        barSizeEdit = new QSpinBox(groupBox_5);
        barSizeEdit->setObjectName(QStringLiteral("barSizeEdit"));
        barSizeEdit->setMinimum(1);
        barSizeEdit->setMaximum(1000000000);
        barSizeEdit->setValue(10);

        horizontalLayout_5->addWidget(barSizeEdit);

        unitsVarBar = new QComboBox(groupBox_5);
        unitsVarBar->addItem(QString());
        unitsVarBar->addItem(QString());
        unitsVarBar->setObjectName(QStringLiteral("unitsVarBar"));

        horizontalLayout_5->addWidget(unitsVarBar);


        verticalLayout_4->addLayout(horizontalLayout_5);

        applyVarBarsButton = new QPushButton(groupBox_5);
        applyVarBarsButton->setObjectName(QStringLiteral("applyVarBarsButton"));

        verticalLayout_4->addWidget(applyVarBarsButton);


        gridLayout_8->addLayout(verticalLayout_4, 0, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_5);


        gridLayout_15->addLayout(verticalLayout_5, 0, 0, 2, 1);

        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_14 = new QGridLayout(groupBox_8);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_7 = new QLabel(groupBox_8);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_14->addWidget(label_7, 0, 0, 1, 1);

        applyCutoffButton = new QPushButton(groupBox_8);
        applyCutoffButton->setObjectName(QStringLiteral("applyCutoffButton"));

        gridLayout_14->addWidget(applyCutoffButton, 2, 0, 1, 1);

        editCutoffVar = new QDoubleSpinBox(groupBox_8);
        editCutoffVar->setObjectName(QStringLiteral("editCutoffVar"));
        editCutoffVar->setDecimals(5);
        editCutoffVar->setMaximum(50000);
        editCutoffVar->setSingleStep(0.1);

        gridLayout_14->addWidget(editCutoffVar, 1, 0, 1, 1);


        gridLayout_15->addWidget(groupBox_8, 0, 1, 1, 1);

        groupBox_9 = new QGroupBox(tab_3);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_16 = new QGridLayout(groupBox_9);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        label_8 = new QLabel(groupBox_9);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_16->addWidget(label_8, 0, 0, 1, 1);

        boxPlotButton = new QPushButton(groupBox_9);
        boxPlotButton->setObjectName(QStringLiteral("boxPlotButton"));

        gridLayout_16->addWidget(boxPlotButton, 1, 0, 1, 1);


        gridLayout_15->addWidget(groupBox_9, 1, 1, 1, 1);

        processBox->addTab(tab_3, QString());

        gridLayout_4->addWidget(processBox, 0, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        gridLayout_13 = new QGridLayout(widget);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        notebookButton = new QPushButton(widget);
        notebookButton->setObjectName(QStringLiteral("notebookButton"));
        notebookButton->setIcon(icon6);
        notebookButton->setIconSize(QSize(32, 32));

        gridLayout_13->addWidget(notebookButton, 0, 0, 1, 1);

        plotstngsButton = new QPushButton(widget);
        plotstngsButton->setObjectName(QStringLiteral("plotstngsButton"));
        plotstngsButton->setIcon(icon5);
        plotstngsButton->setIconSize(QSize(32, 32));

        gridLayout_13->addWidget(plotstngsButton, 1, 0, 1, 1);


        gridLayout_4->addWidget(widget, 0, 1, 1, 1);

        widgetNotebook = new QWidget(centralWidget);
        widgetNotebook->setObjectName(QStringLiteral("widgetNotebook"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widgetNotebook->sizePolicy().hasHeightForWidth());
        widgetNotebook->setSizePolicy(sizePolicy4);
        gridLayout_9 = new QGridLayout(widgetNotebook);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        extractSettingsButton = new QPushButton(widgetNotebook);
        extractSettingsButton->setObjectName(QStringLiteral("extractSettingsButton"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/new/icons/Icons/noteSettings.png"), QSize(), QIcon::Normal, QIcon::Off);
        extractSettingsButton->setIcon(icon13);
        extractSettingsButton->setIconSize(QSize(32, 32));

        gridLayout_9->addWidget(extractSettingsButton, 2, 1, 1, 1);

        groupBox_7 = new QGroupBox(widgetNotebook);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        gridLayout_12 = new QGridLayout(groupBox_7);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        spinBoxWidth = new QSpinBox(groupBox_7);
        spinBoxWidth->setObjectName(QStringLiteral("spinBoxWidth"));
        spinBoxWidth->setMaximum(1000);
        spinBoxWidth->setValue(500);

        verticalLayout_7->addWidget(spinBoxWidth);

        spinBoxHeight = new QSpinBox(groupBox_7);
        spinBoxHeight->setObjectName(QStringLiteral("spinBoxHeight"));
        spinBoxHeight->setMaximum(1000);
        spinBoxHeight->setValue(300);

        verticalLayout_7->addWidget(spinBoxHeight);


        gridLayout_12->addLayout(verticalLayout_7, 0, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_7, 1, 1, 1, 1);

        saveNotebookButton = new QPushButton(widgetNotebook);
        saveNotebookButton->setObjectName(QStringLiteral("saveNotebookButton"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/new/icons/Icons/noteSave.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveNotebookButton->setIcon(icon14);
        saveNotebookButton->setIconSize(QSize(32, 32));

        gridLayout_9->addWidget(saveNotebookButton, 3, 1, 1, 1);

        clearNotebookButton = new QPushButton(widgetNotebook);
        clearNotebookButton->setObjectName(QStringLiteral("clearNotebookButton"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/new/icons/Icons/noteClear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearNotebookButton->setIcon(icon15);
        clearNotebookButton->setIconSize(QSize(32, 32));

        gridLayout_9->addWidget(clearNotebookButton, 4, 1, 1, 1);

        extractPlotButton = new QPushButton(widgetNotebook);
        extractPlotButton->setObjectName(QStringLiteral("extractPlotButton"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/new/icons/Icons/noteGraph.png"), QSize(), QIcon::Normal, QIcon::Off);
        extractPlotButton->setIcon(icon16);
        extractPlotButton->setIconSize(QSize(32, 32));

        gridLayout_9->addWidget(extractPlotButton, 0, 1, 1, 1);

        notebookTextEdit = new QTextEdit(widgetNotebook);
        notebookTextEdit->setObjectName(QStringLiteral("notebookTextEdit"));

        gridLayout_9->addWidget(notebookTextEdit, 0, 0, 6, 1);

        verticalSpacer_2 = new QSpacerItem(20, 442, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer_2, 5, 1, 1, 1);


        gridLayout_4->addWidget(widgetNotebook, 0, 2, 3, 1);

        widgetPlotSettings = new QWidget(centralWidget);
        widgetPlotSettings->setObjectName(QStringLiteral("widgetPlotSettings"));
        sizePolicy1.setHeightForWidth(widgetPlotSettings->sizePolicy().hasHeightForWidth());
        widgetPlotSettings->setSizePolicy(sizePolicy1);
        gridLayout_11 = new QGridLayout(widgetPlotSettings);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        groupBox_6 = new QGroupBox(widgetPlotSettings);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        sizePolicy3.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy3);
        gridLayout_10 = new QGridLayout(groupBox_6);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        radioAllFiles = new QRadioButton(groupBox_6);
        radioAllFiles->setObjectName(QStringLiteral("radioAllFiles"));
        sizePolicy2.setHeightForWidth(radioAllFiles->sizePolicy().hasHeightForWidth());
        radioAllFiles->setSizePolicy(sizePolicy2);
        radioAllFiles->setChecked(false);

        horizontalLayout_6->addWidget(radioAllFiles);

        comboPlotType = new QComboBox(groupBox_6);
        comboPlotType->addItem(QString());
        comboPlotType->addItem(QString());
        comboPlotType->setObjectName(QStringLiteral("comboPlotType"));

        horizontalLayout_6->addWidget(comboPlotType);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        radioSignleFile = new QRadioButton(groupBox_6);
        radioSignleFile->setObjectName(QStringLiteral("radioSignleFile"));
        sizePolicy2.setHeightForWidth(radioSignleFile->sizePolicy().hasHeightForWidth());
        radioSignleFile->setSizePolicy(sizePolicy2);
        radioSignleFile->setChecked(true);

        horizontalLayout_7->addWidget(radioSignleFile);

        comboPlotSettingsFiles = new QComboBox(groupBox_6);
        comboPlotSettingsFiles->setObjectName(QStringLiteral("comboPlotSettingsFiles"));

        horizontalLayout_7->addWidget(comboPlotSettingsFiles);


        verticalLayout_6->addLayout(horizontalLayout_7);


        gridLayout_10->addLayout(verticalLayout_6, 0, 0, 1, 1);

        plotButton = new QPushButton(groupBox_6);
        plotButton->setObjectName(QStringLiteral("plotButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(plotButton->sizePolicy().hasHeightForWidth());
        plotButton->setSizePolicy(sizePolicy5);

        gridLayout_10->addWidget(plotButton, 0, 1, 1, 1);


        gridLayout_11->addWidget(groupBox_6, 0, 0, 1, 1);


        gridLayout_4->addWidget(widgetPlotSettings, 1, 0, 1, 1);

        plot = new CustomPlotZoom(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        sizePolicy4.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy4);

        gridLayout_4->addWidget(plot, 2, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 923, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuAnalysis = new QMenu(menuBar);
        menuAnalysis->setObjectName(QStringLiteral("menuAnalysis"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAnalysis->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionImport);
        menuFile->addAction(actionAppend);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuTools->addAction(actionManipulation);
        menuTools->addAction(actionNotebook);
        menuTools->addAction(actionPlot_Settings);
        menuTools->addAction(actionExtract_variance);
        menuAnalysis->addAction(actionFast_Import);
        menuAnalysis->addSeparator();
        menuAnalysis->addAction(actionFlattening);
        menuAnalysis->addAction(actionFiltering);
        menuAnalysis->addAction(actionFFT);
        menuAnalysis->addAction(actionVariance);
        menuHelp->addAction(actionManual);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionImport);
        mainToolBar->addAction(actionAppend);
        mainToolBar->addAction(actionFast_Import);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionFlattening);
        mainToolBar->addAction(actionFiltering);
        mainToolBar->addAction(actionFFT);
        mainToolBar->addAction(actionVariance);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionNotebook);
        mainToolBar->addAction(actionPlot_Settings);
        mainToolBar->addAction(actionManipulation);

        retranslateUi(MainWindow);
        QObject::connect(notebookButton, SIGNAL(toggled(bool)), widgetNotebook, SLOT(setVisible(bool)));
        QObject::connect(plotstngsButton, SIGNAL(toggled(bool)), widgetPlotSettings, SLOT(setVisible(bool)));
        QObject::connect(radioAllFiles, SIGNAL(toggled(bool)), comboPlotSettingsFiles, SLOT(setDisabled(bool)));
        QObject::connect(radioSignleFile, SIGNAL(toggled(bool)), comboPlotType, SLOT(setDisabled(bool)));
        QObject::connect(actionNotebook, SIGNAL(triggered()), notebookButton, SLOT(click()));
        QObject::connect(actionPlot_Settings, SIGNAL(triggered()), plotstngsButton, SLOT(click()));

        processBox->setCurrentIndex(0);
        unitsFlatWin->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NanoSignal", nullptr));
        actionImport->setText(QApplication::translate("MainWindow", "Import", nullptr));
        actionFast_Import->setText(QApplication::translate("MainWindow", "Fast Analysis", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionAppend->setText(QApplication::translate("MainWindow", "Append", nullptr));
        actionManipulation->setText(QApplication::translate("MainWindow", "Manipulation", nullptr));
        actionPlot_Settings->setText(QApplication::translate("MainWindow", "Plot Settings", nullptr));
        actionNotebook->setText(QApplication::translate("MainWindow", "Notebook", nullptr));
        actionFlattening->setText(QApplication::translate("MainWindow", "Flattening", nullptr));
        actionFiltering->setText(QApplication::translate("MainWindow", "Filtering", nullptr));
        actionFFT->setText(QApplication::translate("MainWindow", "FFT", nullptr));
        actionVariance->setText(QApplication::translate("MainWindow", "Variance", nullptr));
        actionManual->setText(QApplication::translate("MainWindow", "Manual", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionExtract_variance->setText(QApplication::translate("MainWindow", "Extract variance", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Window Options", nullptr));
        isWindowedCheck->setText(QApplication::translate("MainWindow", "Apply Window", nullptr));
        label->setText(QApplication::translate("MainWindow", "Window Size:", nullptr));
        unitsFlatWin->setItemText(0, QApplication::translate("MainWindow", "Samples", nullptr));
        unitsFlatWin->setItemText(1, QApplication::translate("MainWindow", "Seconds", nullptr));

        groupBox_2->setTitle(QApplication::translate("MainWindow", "Fit Options", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Type", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "Polynomial", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "Order", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Fit Preview", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Choose a preview file:", nullptr));
        fitPreviewButton->setText(QApplication::translate("MainWindow", "Fit Preview", nullptr));
        ApplyFlatButton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        processBox->setTabText(processBox->indexOf(tab), QApplication::translate("MainWindow", "Flattening", nullptr));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "Moving Average", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Window size:", nullptr));
        unitsFiltWin->setItemText(0, QApplication::translate("MainWindow", "Samples", nullptr));
        unitsFiltWin->setItemText(1, QApplication::translate("MainWindow", "Seconds", nullptr));

        groupBox_13->setTitle(QApplication::translate("MainWindow", "Filter Preview", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Choose a preview file:", nullptr));
        filterPreviewButton->setText(QApplication::translate("MainWindow", "Filter Preview", nullptr));
        applyMovAvgButton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        processBox->setTabText(processBox->indexOf(tab_2), QApplication::translate("MainWindow", "Filtering", nullptr));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "FFT Settings", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p>FFT calculations are limited to the input size of type: 2<span style=\" vertical-align:super;\">x</span>.<br/><span style=\" font-style:italic;\">X</span> is chosen so that as many points are included.</p></body></html>", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Sampling Frequency:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Hz", nullptr));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "FFT Preview", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Choose a preview file:", nullptr));
        calcSingleFFTButton->setText(QApplication::translate("MainWindow", "FFT Preview", nullptr));
        applyFFTbutton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        processBox->setTabText(processBox->indexOf(tab_4), QApplication::translate("MainWindow", "FFT", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Variance Evolution", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Window Size:", nullptr));
        unitsVarWin->setItemText(0, QApplication::translate("MainWindow", "Samples", nullptr));
        unitsVarWin->setItemText(1, QApplication::translate("MainWindow", "Seconds", nullptr));

        ApplyVarButton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Variance Bars", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Bar size:", nullptr));
        unitsVarBar->setItemText(0, QApplication::translate("MainWindow", "Samples", nullptr));
        unitsVarBar->setItemText(1, QApplication::translate("MainWindow", "Seconds", nullptr));

        applyVarBarsButton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Cutoff", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Cutoff variance:", nullptr));
        applyCutoffButton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Box Plot", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Whole-file box plot", nullptr));
        boxPlotButton->setText(QApplication::translate("MainWindow", "Apply", nullptr));
        processBox->setTabText(processBox->indexOf(tab_3), QApplication::translate("MainWindow", "Variance", nullptr));
        notebookButton->setText(QApplication::translate("MainWindow", "Notebook", nullptr));
        plotstngsButton->setText(QApplication::translate("MainWindow", "Plot\n"
"Settings", nullptr));
        extractSettingsButton->setText(QApplication::translate("MainWindow", "Extract\n"
"Settings", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Plot Size", nullptr));
        saveNotebookButton->setText(QApplication::translate("MainWindow", "Save\n"
"Notebook", nullptr));
        clearNotebookButton->setText(QApplication::translate("MainWindow", "Clear\n"
"Notebook", nullptr));
        extractPlotButton->setText(QApplication::translate("MainWindow", "Extract\n"
"Plot", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Plot Settings", nullptr));
        radioAllFiles->setText(QApplication::translate("MainWindow", "All Files", nullptr));
        comboPlotType->setItemText(0, QApplication::translate("MainWindow", "Subsequential", nullptr));
        comboPlotType->setItemText(1, QApplication::translate("MainWindow", "Stacked", nullptr));

        radioSignleFile->setText(QApplication::translate("MainWindow", "Single File", nullptr));
        plotButton->setText(QApplication::translate("MainWindow", "Plot", nullptr));
#ifndef QT_NO_TOOLTIP
        plot->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Left click: navigation</p><p>Right click: zoom in region of interest</p><p>Mouse wheel: zoom in &amp; out </p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", nullptr));
        menuAnalysis->setTitle(QApplication::translate("MainWindow", "Analysis", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
