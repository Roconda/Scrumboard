#include "sbinotstartedlistmodel.h"
#include "TFS/TFSTransaction.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <iostream>

using std::string;

SBINotStartedListModel::SBINotStartedListModel(QObject *parent)
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
        std::cerr << "Kon geen verbinding maken met de TFS server";
    }
    /* Einde TFS test */
}

int SBINotStartedListModel::rowCount(const QModelIndex &parent) const
{
    return SBIList.size();
}

QVariant SBINotStartedListModel::data(const QModelIndex &index, int role) const
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

QVariant SBINotStartedListModel::headerData(int section, Qt::Orientation orientation,
                                            int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}
