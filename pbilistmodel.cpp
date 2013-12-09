#include "pbilistmodel.h"
#include "tfswrapper.h"
#include "TFS/Sprint.h"

PBIListModel::PBIListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    /* wrapper test/voorbeeld */
    TFSWrapper wrapper = TFSWrapper::instance();
    //wrapper.getSelectedSprint()->getWorkItem
}

int PBIListModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant PBIListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        throw std::exception("Index is invalid");
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
