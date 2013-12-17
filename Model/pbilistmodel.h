#ifndef PBILISTMODEL_H
#define PBILISTMODEL_H

#include <QAbstractListModel>
#include <vector>

#include "../TFS/ProductBacklogItem.h"

using std::vector;

class PBIListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PBIListModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
private:
    vector<ProductBacklogItem*> PBIList;

public slots:
    void refreshTFSData();
};

#endif // PBILISTMODEL_H
