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
    adddefect.cpp \
    lanedelegate.cpp \
    workitem.cpp \
    notstartedlane.cpp

HEADERS  += mainwindow.h \
    defect.h \
    qcustomplot/qcustomplot.h \
    burndownchart.h \
    sbi.h \
    adddefect.h \
    lanedelegate.h \
    workitem.h \
    notstartedlane.h

FORMS    += mainwindow.ui \
    defect.ui \
    burndownchart.ui \
    sbi.ui \
    adddefect.ui
