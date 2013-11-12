#include "lanedelegate.h"
#include <QtGui>
#include "workitem.h"
#include <QGridLayout>

LaneDelegate::LaneDelegate(QWidget *parent) :
    QWidget(parent)
{
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

void LaneDelegate::paintEvent(QPaintEvent *e)
{
    QPainter qp(this);
    drawWidget(qp);
}

void LaneDelegate::drawWidget(QPainter &qp)
{
    QPen pen;
    pen.setColor(QColor(Qt::red));
    pen.setWidth(5);
    qp.setPen(pen);
    qp.drawRect(0,0,this->width()-1,this->height()-1);
}
