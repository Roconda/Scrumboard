#ifndef USERLISTMODEL_H
#define USERLISTMODEL_H

#include <QAbstractListModel>
#include <QVariant>
#include <vector>
#include <QObject>

#include "../TFS/User.h"

class UserListModel : public QAbstractListModel
{
public:
    explicit UserListModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    std::vector<User*> UserList;

private slots:
    void refreshTFSData();
};

#endif // USERLISTMODEL_H
