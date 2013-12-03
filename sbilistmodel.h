#ifndef SBILISTMODEL_H
#define SBILISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <vector>

#include "TFS/WorkItem.h"

using std::vector;

class SBIListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum SBIDisplayRoles {
            TitleRole = Qt::UserRole,
            DescriptionRole,
            IDRole,
            RemainingHoursRole,
            PriorityRole,
            UserRole
    };

    explicit SBIListModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;


private:
    vector<WorkItem*> SBIList;
};

#endif // SBILISTMODEL_H
