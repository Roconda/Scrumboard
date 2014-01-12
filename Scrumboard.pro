#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T20:03:14
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Scrumboard
TEMPLATE = app

win32-msvc*: QMAKE_LFLAGS += /VERBOSE
LIBS     += -lws2_32 -L./

SOURCES += main.cpp \
        View/mainwindow.cpp \
        qcustomplot/qcustomplot.cpp \
        View/burndownchart.cpp \
        View/sbi.cpp \
        View/adddefect.cpp \
        View/itemui.cpp \
        View/laneui.cpp \
        View/scrumboardwidget.cpp \
    	TFS/WriteData.cpp \
    	TFS/WorkItem.cpp \
    	TFS/User.cpp \
    	TFS/UniqueKey.cpp \
    	TFS/TFSTransaction.cpp \
    	TFS/TFSBasisFactory.cpp \
    	TFS/TFSBasis.cpp \
    	TFS/TFSActionFactory.cpp \
    	TFS/TFSActionDecorator.cpp \
    	TFS/TFSAction.cpp \
    	TFS/StatusType.cpp \
    	TFS/Status.cpp \
    	TFS/SprintBacklogItem.cpp \
    	TFS/Sprint.cpp \
    	TFS/SocketPackage.cpp \
    	TFS/SocketClient.cpp \
    	TFS/RemainingWorkHistory.cpp \
    	TFS/ReadData.cpp \
    	TFS/Project.cpp \
    	TFS/ProductBacklogItem.cpp \
    	TFS/PracticalSocket.cpp \
    	TFS/ObjectStoredInStack.cpp \
    	TFS/ListData.cpp \
    	TFS/ItemStorage.cpp \
    	TFS/general.cpp \
    	TFS/Defect.cpp \
    	TFS/Date.cpp \
        TFS/Attachment.cpp \
    itemmimedata.cpp \
    tfswrapper.cpp \
    Model/sbilistmodel.cpp \
    createtestdata.cpp \
    scrumboardwidgethandler.cpp \
    Model/pbilistmodel.cpp \
    Visitors/sbivisitor.cpp \
    Visitors/pbivisitor.cpp \
    TestData/testdata.cpp \
    TestData/projectcreator.cpp \
    TestData/statustypecreator.cpp \
    TestData/sprintcreator.cpp \
    TestData/sbicreator.cpp \
    TestData/usercreator.cpp \
    TestData/pbicreator.cpp \
    TestData/workhistorycreator.cpp \
    Model/SBIListModelFilter.cpp \
    Model/SBI_TitleFilter.cpp \
    Model/SBI_UsernameFilter.cpp \
    Visitors/defectvisitor.cpp \
    Visitors/workitemstatusvisitor.cpp \
    View/defectui.cpp \
    Model/filterdecorator.cpp \
    Model/simplefilter.cpp \
    Model/filteroption.cpp \
    Model/filter_sbi_title.cpp \
    Model/filter_sbi_username.cpp

HEADERS  += View/mainwindow.h \
    qcustomplot/qcustomplot.h \
    View/burndownchart.h \
    View/sbi.h \
    View/adddefect.h \
    View/itemui.h \
    View/laneui.h \
    View/scrumboardwidget.h \
    TFS/WriteData.h \
    TFS/WorkItem.h \
    TFS/User.h \
    TFS/UniqueKeyItem.hpp \
    TFS/UniqueKeyItem.h \
    TFS/UniqueKey.h \
    TFS/TFSVisitor.h \
    TFS/TFSTransaction.h \
    TFS/TFSConstVisitor.h \
    TFS/TFSBasisFactory.h \
    TFS/TFSBasisCreator.hpp \
    TFS/TFSBasisCreator.h \
    TFS/TFSBasis.hpp \
    TFS/TFSBasis.h \
    TFS/TFSActionFactory.h \
    TFS/TFSActionDecorator.h \
    TFS/TFSAction.h \
    TFS/StatusType.h \
    TFS/Status.h \
    TFS/SprintBacklogItem.h \
    TFS/Sprint.h \
    TFS/SocketSettings.h \
    TFS/SocketServer.h \
    TFS/SocketPackage.h \
    TFS/SocketClient.h \
    TFS/RemainingWorkHistory.h \
    TFS/ReadData.hpp \
    TFS/ReadData.h \
    TFS/Project.h \
    TFS/ProductBacklogItem.h \
    TFS/PracticalSocket.h \
    TFS/ObjectStoredInStack.h \
    TFS/NonUniqueKeyItem.hpp \
    TFS/NonUniqueKeyItem.h \
    TFS/ListData.h \
    TFS/LessThan.h \
    TFS/ItemStorage.hpp \
    TFS/ItemStorage.h \
    TFS/general.h \
    TFS/Defect.h \
    TFS/Date.h \
    TFS/Attachment.h \
    itemmimedata.h \
    tfswrapper.h \
    Model/sbilistmodel.h \
    createtestdata.h \
    Model/pbilistmodel.h \
    scrumboardwidgethandler.h \
    Visitors/sbivisitor.h \
    Visitors/pbivisitor.h \
    TestData/testdata.h \
    TestData/projectcreator.h \
    TestData/statustypecreator.h \
    TestData/sprintcreator.h \
    TestData/sbicreator.h \
    TestData/usercreator.h \
    TestData/pbicreator.h \
    TestData/workhistorycreator.h \
    Model/SBIListModelFilter.h \
    Model/SBI_TitleFilter.h \
    Model/SBI_UsernameFilter.h \
    Visitors/defectvisitor.h \
    Visitors/workitemstatusvisitor.h \
    View/defectui.h \
    Model/filterdecorator.h \
    Model/simplefilter.h \
    Model/filteroption.h \
    Model/filter_sbi_title.h \
    Model/filter_sbi_username.h

FORMS    += View/mainwindow.ui \
    View/burndownchart.ui \
    View/sbi.ui \
    View/adddefect.ui \
    View/itemui.ui \
    View/laneui.ui \
    View/scrumboardwidget.ui \
    View/defectui.ui

RC_FILE	+= scrumbag.rc

OTHER_FILES +=
