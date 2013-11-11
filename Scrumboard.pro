#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T20:03:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Scrumboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        defect.cpp \
        qcustomplot/qcustomplot.cpp \
        burndownchart.cpp \
        sbi.cpp \
    userstorydelegate.cpp \
    adddefect.cpp

HEADERS  += mainwindow.h \
    defect.h \
    qcustomplot/qcustomplot.h \
    burndownchart.h \
    sbi.h \
    userstorydelegate.h \
    adddefect.h

FORMS    += mainwindow.ui \
    defect.ui \
    burndownchart.ui \
    sbi.ui \
    adddefect.ui
