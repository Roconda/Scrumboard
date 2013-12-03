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
        if (wi)
            this->SBIList.push_back(wi);
    });

    // oud:
//    for_each(begin(wia), end(wia), [&](WorkItem *wi){
//        if (wi) {
//            sbiItem temp;
//            temp.titel = wi->getTitle();
//            temp.id = wi->getWorkItemNumber();
//            temp.description = wi->getDescription();
//            temp.remainingHours = "TODO";
//            temp.priority = "TODO";
//            temp.user = "TODO";
//            SBIList.push_back(temp);
//        }
//    });
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
        // FIXME remaininghours opvragen.
        return QString("TODO");
    else if (role == PriorityRole)
        // FIXME priority opvragen.
        return QString("TODO");
    else if (role == UserRole)
        // FIXME users opvragen.
        return QString("TODO");
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
