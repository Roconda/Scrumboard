#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>

#include "sbilistmodel.h"
#include "../tfswrapper.h"
#include "../TFS/TFSTransaction.h"
#include "../TFS/Project.h"
#include "../TFS/WorkItem.h"
#include "../TFS/SprintBacklogItem.h"
#include "../TFS/ProductBacklogItem.h"
#include "../TFS/Sprint.h"
#include "../TFS/User.h"
#include "../TFS/Status.h"
#include "../TFS/StatusType.h"
#include "../Visitors/sbivisitor.h"
#include "../Visitors/pbivisitor.h"
#include "../Visitors/defectvisitor.h"
#include "../Visitors/workitemstatusvisitor.h"
#include "SBIListModelFilter.h"
#include "SBI_UsernameFilter.h"
#include "SBI_TitleFilter.h"
#include <QDebug>


using std::string;
using std::cerr;
using std::vector;

SBIListModel::SBIListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    /* wrapper test/voorbeeld */

    QObject::connect(&TFSWrapper::instance(), SIGNAL(remoteTFSDataChanged()),
		this, SLOT(refreshTFSData()));
    refreshTFSData();
}

void SBIListModel::Filter(FilterType type, QString phrase)
{
    SBIListModelFilter* filter = SetFilter(type);
    workitemList = filter->Filter(workitemList, phrase);
}

SBIListModelFilter* SBIListModel::SetFilter(FilterType type)
{
    switch(type)
    {
        case USERNAME:
            return new SBI_UsernameFilter;
            break;
        case SBI_TITLE:
            return new SBI_TitleFilter;
            break;
    }
}

int SBIListModel::rowCount(const QModelIndex &parent) const
{
    return workitemList.size();
}

QVariant SBIListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        throw std::exception("Index is invalid");

    if (index.row() >= workitemList.size())
        throw std::out_of_range("Index out of range");

    if (workitemList[index.row()] == nullptr)
        return QVariant();

    WorkItemStatusVisitor wisvis;
    workitemList[index.row()]->accept(wisvis);

    Status *stat = wisvis.getStatus();

    QMap<QString, QVariant> temp;

    if (stat) {
        QMap<QString, QVariant> sbiData;

        sbiData.insert("Title", workitemList[index.row()]->getTitle());
        sbiData.insert("Description", workitemList[index.row()]->getDescription());
        sbiData.insert("WorkItemNumber", workitemList[index.row()]->getWorkItemNumber());

        SBIVisitor sbivis;
        workitemList[index.row()]->accept(sbivis);
        if(!sbivis.getList().empty()){
            QString remaining = QString::number(sbivis.getList()[0]->getRemainingWork());
            QString total = QString::number(sbivis.getList()[0]->getBaselineWork());
            sbiData.insert("RemainingHours", QString(total + "/" + remaining));
        }

        auto test = workitemList[index.row()];
        for (int i = 0; i < PBIList.size(); i++) {
            if(ProductBacklogItem* pbi = PBIList.at(i)) {
                auto array = pbi->getBacklogItemArray();
                for(int j = 0; j < array.size(); j++) {
                    if(SprintBacklogItem* sbi = array.at(j)) {
                        if(sbi->getWorkItemNumber() == test->getWorkItemNumber()) {
                            sbiData.insert("Priority", pbi->getPriority());
                        }
                    }
                }
            }
        }

        User *u = workitemList[index.row()]->getUser();
        if (u)
            sbiData.insert("UserName", QString(u->getName()));
        else
            sbiData.insert("UserName", QString("Not assigned"));

        if (strcmp(stat->getStatusType()->getName(), "Not Started") == 0 && role == SBIDisplayRoles::NotStarted)
            return sbiData;
        else if (strcmp(stat->getStatusType()->getName(), "Started") == 0 && role == SBIDisplayRoles::Started)
            return sbiData;
        else if (strcmp(stat->getStatusType()->getName(), "To Verify") == 0 && role == SBIDisplayRoles::ToVerify)
            return sbiData;
        else if (strcmp(stat->getStatusType()->getName(), "Done") == 0 && role == SBIDisplayRoles::Done)
            return sbiData;
        else
            return QVariant();
    }
}

QVariant SBIListModel::headerData(int section, Qt::Orientation orientation,
                                            int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

void SBIListModel::refreshTFSData()
{
    Sprint *s = TFSWrapper::instance().getSelectedSprint();

    if (s) {
        vector<WorkItem*> pbis = s->getWorkItemArray();
        int selectedSBIWorkItemnr = TFSWrapper::instance().getSelectedPBI()->getWorkItemNumber();

        SBIVisitor sbivis;
        PBIVisitor pbivis;
        DefectVisitor defvis;

        for_each(begin(pbis), end(pbis), [&](WorkItem *wi){
            if (wi)
            {
                wi->accept(sbivis);
                wi->accept(pbivis);
                wi->accept(defvis);
            }
        });
        this->workitemList.insert(workitemList.end(), sbivis.getList().begin(), sbivis.getList().end());
        this->workitemList.insert(workitemList.end(), defvis.getList().begin(), defvis.getList().end());

        this->PBIList = pbivis.getList();
    }
}
