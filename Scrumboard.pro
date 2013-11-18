#-------------------------------------------------
#
# Project created by QtCreator 2013-11-05T20:03:14
#
#-------------------------------------------------

QT       += core gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Scrumboard
TEMPLATE = app

LIBS     += -lws2_32

SOURCES += main.cpp \
        mainwindow.cpp \
        defect.cpp \
        qcustomplot/qcustomplot.cpp \
        burndownchart.cpp \
        sbi.cpp \
	adddefect.cpp \
	itemui.cpp \
	laneui.cpp \
	scrumboardwidget.cpp \
    	userstorydelegate.cpp \
	lanedelegate.cpp \
        workitem.cpp \
        sbinotstartedlistmodel.cpp \
    	adddefect.cpp \
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
        TFS/Attachment.cpp

HEADERS  += mainwindow.h \
    qcustomplot/qcustomplot.h \
    defect.h \
    burndownchart.h \
    sbi.h \
    adddefect.h \
    itemui.h \
    laneui.h \
    scrumboardwidget.h \
    sbinotstartedlistmodel.h \
    adddefect.h \
    userstorydelegate.h \
    lanedelegate.h \
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
    TFS/Attachment.h

FORMS    += mainwindow.ui \
    defect.ui \
    burndownchart.ui \
    sbi.ui \
    adddefect.ui \
    itemui.ui \
    laneui.ui \
    scrumboardwidget.ui
