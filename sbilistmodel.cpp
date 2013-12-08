#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>

#include "sbilistmodel.h"
#include "tfswrapper.h"
#include "TFS/TFSTransaction.h"
#include "TFS/Project.h"
#include "TFS/WorkItem.h"
#include "TFS/SprintBacklogItem.h"
#include "TFS/Sprint.h"
#include "TFS/User.h"

using std::string;
using std::cerr;
using std::vector;

SBIListModel::SBIListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    /* wrapper test/voorbeeld */
    TFSWrapper wrapper = TFSWrapper::instance();

    Sprint *s = wrapper.getSelectedSprint();

    if (s) {
        auto wia = s->getWorkItemArray();
        for_each(begin(wia), end(wia), [&](WorkItem *wi){
            if (wi)
                this->SBIList.push_back( (SprintBacklogItem *) wi );
        });
    }
}

int SBIListModel::rowCount(const QModelIndex &parent) const
{
    return SBIList.size();
}

QVariant SBIListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        throw std::exception("Index is invalid");

    if (index.row() >= SBIList.size())
        throw std::out_of_range("Index out of range");

    if (SBIList[index.row()] == nullptr)
        return QVariant();

    if (role == TitleRole)
        return SBIList[index.row()]->getTitle();
    else if (role == DescriptionRole)
        return SBIList[index.row()]->getDescription();
    else if (role == IDRole)
        return SBIList[index.row()]->getWorkItemNumber();
    else if (role == RemainingHoursRole)
    {
        QString remaining = QString::number(SBIList[index.row()]->getRemainingWork());
        QString total = QString::number(SBIList[index.row()]->getBaselineWork());
        return QString(total + "/" + remaining);
    }
    else if (role == UserRole) {
        User *u = SBIList[index.row()]->getUser();
        if (u)
            return QString(u->getName());
        else
            return QString("Not assigned");
    } else
        return QVariant();
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
