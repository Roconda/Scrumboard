#include <algorithm>

#include "pbilistmodel.h"
#include "../tfswrapper.h"
#include "../TFS/Sprint.h"
#include "../TFS/ProductBacklogItem.h"

using std::for_each;

PBIListModel::PBIListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    /* wrapper test/voorbeeld */
    TFSWrapper wrapper = TFSWrapper::instance();

    auto wia = wrapper.getSelectedSprint()->getWorkItemArray();
    for_each(begin(wia), end(wia), [&](WorkItem *pbi) {
        this->PBIList.push_back((ProductBacklogItem *) pbi);
    });
}

int PBIListModel::rowCount(const QModelIndex &parent) const
{
    return PBIList.size();
}

QVariant PBIListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        throw std::exception("Index is invalid");

    if (role == Qt::DisplayRole)
        return QVariant();
        //return QString() + PBIList.at(index.row());
    else
        return QVariant();
}

QVariant PBIListModel::headerData(int section, Qt::Orientation orientation,
                                    int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}
