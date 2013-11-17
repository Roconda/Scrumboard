#include "sbilistmodel.h"
#include "TFS/TFSTransaction.h"

#include <algorithm>
#include <string>

using std::string;

SBIListModel::SBIListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // TODO TFS connectie, data vullen etc

    /* TFS test! */

    std::list<string> saFilenameList;

    try {
        TFSTransaction::remoteListProjects( saFilenameList );
        for_each(begin(saFilenameList), end(saFilenameList), [&](string s) {
            SBIList << s.c_str();
        });
    } catch(...) {

    }

    /* Einde TFS test */
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

    if (role == Qt::DisplayRole)
        return SBIList[index.row()];
    else if (role == Qt::ToolTipRole)
        return QString("Tooltip test!");
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
