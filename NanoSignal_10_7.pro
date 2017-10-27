#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T00:02:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport concurrent

TARGET = NanoSignal_10_7
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    data.cpp \
    process.cpp \
    reader.cpp \
    flattener.cpp \
    variance.cpp \
    qcpdocumentobject.cpp \
    plotter.cpp \
    notebook.cpp \
    fourier.cpp \
    filter.cpp \
    customplotzoom.cpp \
    manipulation.cpp \
    system.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    types.h \
    data.h \
    process.h \
    reader.h \
    flattener.h \
    variance.h \
    qcpdocumentobject.h \
    plotter.h \
    notebook.h \
    fourier.h \
    fft.h \
    filter.h \
    customplotzoom.h \
    manipulation.h \
    system.h \
    polynomialFit.h

FORMS    += mainwindow.ui \
    manipulation.ui

QMAKE_CXXFLAGS += -O3 -Wall -I/usr/include/python2.7 -lpython2.7
CONFIG += c++11

DISTFILES +=

RESOURCES += \
    icons.qrc \
    files.qrc \
    splash.qrc
