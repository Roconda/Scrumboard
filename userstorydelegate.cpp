#include "userstorydelegate.h"
#include <QPainter>

userStoryDelegate::userStoryDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}

QSize userStoryDelegate::sizeHint(const QStyleOptionViewItem & option ,
const QModelIndex & index) const
{
    return QSize(50, 50);
}

void userStoryDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
const QModelIndex &index) const
{
    painter->drawRect(0, 0, 50, 50);

    QString s = index.data().toString();
    painter->drawText(0, 0, s);
}
