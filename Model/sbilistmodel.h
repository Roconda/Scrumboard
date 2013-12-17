#ifndef SBILISTMODEL_H
#define SBILISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <vector>
#include "../TFS/SprintBacklogItem.h"
#include "../TFS/ProductBacklogItem.h"

using std::vector;

// forward declarations
class SprintBacklogItem;



namespace SBIDisplayRoles {
    enum SBIDisplayRoles {
            NotStarted = Qt::UserRole,
            Started,
            ToVerify,
            Done
    };
}

class SBIListModel : public QAbstractListModel
{
    Q_OBJECT
public:

    explicit SBIListModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    void FilterWithUsername(QString username = "all");

private:
    vector<SprintBacklogItem*> SBIList;
    vector<ProductBacklogItem*> PBIList;
};

#endif // SBILISTMODEL_H
