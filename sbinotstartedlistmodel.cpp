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
    sbiItem t1, t2;
    t1.id = 2;
    t1.titel = "Test1";
    t1.description = "Beschrijving1";

    t2.id = 42;
    t2.titel = "De titel";
    t2.description = "Test 12345";

    SBIList.push_back(t1);
    SBIList.push_back(t2);

    /* TFS test! */
    std::list<string> saFilenameList;

    try {
        TFSTransaction::remoteListProjects( saFilenameList );
        for_each(begin(saFilenameList), end(saFilenameList), [&](string s) {
            sbiItem temp;
            temp.titel = s.c_str();
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

    if (role == TitleRole)
        return SBIList[index.row()].titel;
    else if (role == DescriptionRole)
        return SBIList[index.row()].description;
    else if (role == IDRole)
        return SBIList[index.row()].id;
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
