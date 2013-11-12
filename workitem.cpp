#include "workitem.h"
#include <QtGui>
#include "sbi.h"
#include "lanedelegate.h"
#include "mainwindow.h"

QPen pen;

WorkItem::WorkItem(QWidget *parent) :
    QWidget(parent)
{
    this->resize(101,101);
    this->move(5,5);
}

void WorkItem::paintEvent(QPaintEvent *e)
{
    QPainter qp(this);
    drawWidget(qp);
}

void WorkItem::drawWidget(QPainter &qp)
{
    qp.setPen(pen);
    qp.drawRect(0,0,100,100);

    QString s = "Item 1";
    QFont f;
    f.setBold(true);
    qp.setFont(f);
    qp.drawStaticText(5,5,s);

    f.setBold(false);
    qp.setFont(f);
    QString s2 = "Dit is WorkItem1";
    qp.drawStaticText(5,20,s2);
}

void WorkItem::mouseDoubleClickEvent(QMouseEvent *event){
    SBI *sbi1 = new SBI();
    sbi1->exec();
}

void WorkItem::mousePressEvent(QMouseEvent *event){
    pen.setColor(QColor(Qt::blue));
    pen.setWidth(3);
}

void WorkItem::mouseMoveEvent(QMouseEvent *event){
    this->move(this->x()+event->x()-(this->width()/2), this->y()+event->y()-(this->height()/2));
}

void WorkItem::mouseReleaseEvent(QMouseEvent *event){
    pen.setColor(QColor(Qt::black));
    pen.setWidth(1);
    repaint();
}
