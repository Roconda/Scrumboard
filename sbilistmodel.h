#ifndef SBILISTMODEL_H
#define SBILISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

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
    struct sbiItem {
        QString titel;
        QString description;
        int id;
        QString remainingHours;
        QString priority;
        QString user;
    } ;
    QList<sbiItem> SBIList;
};

#endif // SBILISTMODEL_H
