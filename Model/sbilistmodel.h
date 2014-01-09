#ifndef SBILISTMODEL_H
#define SBILISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <vector>
#include "../TFS/SprintBacklogItem.h"
#include "../TFS/ProductBacklogItem.h"
#include "../TFS/Defect.h"
#include "SBIListModelFilter.h"

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

enum FilterType
{
    USERNAME = 0,
    SBI_TITLE = 1
};

class SBIListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SBIListModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    void Filter(FilterType type, QString phrase);
    SBIListModelFilter* SetFilter(FilterType type);

private:
    vector<ProductBacklogItem*> PBIList;
    vector<WorkItem*> workitemList;

private slots:
    void refreshTFSData();
};

#endif // SBILISTMODEL_H
