#include <algorithm>

#include "pbilistmodel.h"
#include "../tfswrapper.h"
#include "../TFS/Sprint.h"
#include "../TFS/ProductBacklogItem.h"
#include "../Visitors/pbivisitor.h"

using std::for_each;

PBIListModel::PBIListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    /* bind dit model met het tfswrapper tfsupdate signal */

    QObject::connect(&TFSWrapper::instance(), SIGNAL(remoteTFSDataChanged()),
                     this, SLOT(refreshTFSData()));

    refreshTFSData();
}

int PBIListModel::rowCount(const QModelIndex &parent) const
{
    return PBIList.size();
}

QVariant PBIListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        throw std::exception("Index is invalid");

    if (role == Qt::DisplayRole) {
        if (!PBIList.empty() && index.row() < PBIList.size())
            return QString(PBIList.at((index.row()))->getTitle());
        return QVariant();
    } else
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

void PBIListModel::refreshTFSData()
{
    PBIVisitor pbivis;

    auto wia = TFSWrapper::instance().getSelectedSprint()->getWorkItemArray();
    for_each(begin(wia), end(wia), [&](WorkItem *pbi) {
        if (pbi)
            pbi->accept(pbivis);
    });
    this->PBIList = pbivis.getList();
}
