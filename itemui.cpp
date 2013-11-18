#include "itemui.h"
#include "ui_itemui.h"
#include "sbi.h"
#include <QMouseEvent>
#include "laneui.h"

ItemUI::ItemUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemUI)
{
    ui->setupUi(this);
    this->resize(101,101);
    this->move(5,5);

    QString s = "hallo";
    ui->label->setText(s);
}

ItemUI::~ItemUI()
{
    delete ui;
}

void ItemUI::mouseDoubleClickEvent(QMouseEvent *event){
    SBI *sbi1 = new SBI();
    sbi1->exec();
}

void ItemUI::mousePressEvent(QMouseEvent *event){
    /*
    LaneUI *lane = qobject_cast<LaneUI*>(parentWidget());
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::gray);
    lane->setPalette(Pal);
    */
}

void ItemUI::mouseMoveEvent(QMouseEvent *event){
    this->move(this->x()+event->x()-(this->width()/2), this->y()+event->y()-(this->height()/2));
    repaint();
}

void ItemUI::mouseReleaseEvent(QMouseEvent *event){
    repaint();
}
