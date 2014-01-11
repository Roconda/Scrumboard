#include "userlistmodel.h"

#include "../tfswrapper.h"

#include <QString>

UserListModel::UserListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // TODO (?) verbinden met tfswrapepr slot?
    refreshTFSData();
}

int UserListModel::rowCount(const QModelIndex &parent) const
{
    return UserList.size();
}

QVariant UserListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        throw std::exception("Index is invalid");

    if (role == Qt::DisplayRole) {
        return QString(UserList.at(index.row())->getName());
    } else
        return QVariant();
}

void UserListModel::refreshTFSData()
{
    this->UserList = TFSWrapper::instance().getAllUsers();
}
