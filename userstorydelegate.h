#ifndef USERSTORYDELEGATE_H
#define USERSTORYDELEGATE_H

#include <QItemDelegate>

class userStoryDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit userStoryDelegate(QObject *parent = 0);

    QSize sizeHint(const QStyleOptionViewItem & option ,
    const QModelIndex & index) const;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
    const QModelIndex &index) const;

signals:

public slots:

};

#endif // USERSTORYDELEGATE_H
