#ifndef SBINOTSTARTEDLISTMODEL_H
#define SBINOTSTARTEDLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

class SBINotStartedListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SBINotStartedListModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

private:
    QStringList SBIList;
};

#endif // SBINOTSTARTEDLISTMODEL_H
