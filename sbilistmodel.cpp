#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>

#include "sbilistmodel.h"
#include "tfswrapper.h"
#include "TFS/TFSTransaction.h"
#include "TFS/Project.h"
#include "TFS/Sprint.h"
#include "TFS/WorkItem.h"

using std::string;
using std::cerr;
using std::vector;

SBIListModel::SBIListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // TODO TFS connectie, data vullen etc

    /* wrapper test/voorbeeld */
    TFSWrapper wrapper = TFSWrapper::instance();

    // FIXME haal data uit gekozen sprint, niet de eerste.
    Sprint *s = wrapper.getSelectedProject()->getSprint(0);
    auto wia = s->getWorkItemArray();

    for_each(begin(wia), end(wia), [&](WorkItem *wi){
        if (wi) {
            sbiItem temp;
            temp.titel = wi->getTitle();
            temp.id = wi->getWorkItemNumber();
            temp.description = wi->getDescription();
            temp.remainingHours = "TODO";
            temp.priority = "TODO";
            temp.user = "TODO";
            SBIList.push_back(temp);
        }
    });
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

    if (role == TitleRole)
        return SBIList[index.row()].titel;
    else if (role == DescriptionRole)
        return SBIList[index.row()].description;
    else if (role == IDRole)
        return SBIList[index.row()].id;
    else if (role == RemainingHoursRole)
        return SBIList[index.row()].remainingHours;
    else if (role == PriorityRole)
        return SBIList[index.row()].priority;
    else if (role == UserRole)
        return SBIList[index.row()].user;
    else
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
