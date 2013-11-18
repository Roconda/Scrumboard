#include "scrumboardwidget.h"
#include "ui_scrumboardwidget.h"
#include "itemui.h"
#include "laneui.h"
#include <QPainter>
ScrumboardWidget::ScrumboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrumboardWidget)
{
    ui->setupUi(this);
    ItemUI *wi;
    wi = new ItemUI(ui->ToVerify_2);
}

ScrumboardWidget::~ScrumboardWidget()
{
    delete ui;
}

void ScrumboardWidget::moveItem(ItemUI* item){
    item->setParent(this);
    item->move(mapFromGlobal(QCursor::pos()).x() - (item->width()/2) ,mapFromGlobal(QCursor::pos()).y() - (item->height()/2));
    item->show();
}

void ScrumboardWidget::moveItem(ItemUI* item, QPoint pos){
    QRect rect = ui->NotStarted_2->rect();
    rect.moveTo(mapTo(this, ui->NotStarted_2->pos()));

            if (rect.contains(mapFrom(this, QCursor::pos()))) {
                item->setParent(ui->NotStarted_2);
                item->move(5,5);
                item->show();
            }
            rect = ui->Started_2->rect();
                rect.moveTo(mapTo(this, ui->Started_2->pos()));

            if(rect.contains(mapFrom(this, QCursor::pos()))) {
                item->setParent(ui->Started_2);
                item->move(5,5);
                item->show();
            }

                rect = ui->ToVerify_2->rect();
                rect.moveTo(mapTo(this, ui->ToVerify_2->pos()));

            if(rect.contains(mapFrom(this, QCursor::pos()))) {
                item->setParent(ui->ToVerify_2);
                item->move(5,5);
                item->show();
            }

            rect = ui->Done_2->rect();
                rect.moveTo(mapTo(this, ui->Done_2->pos()));

            if(rect.contains(mapFrom(this, QCursor::pos()))) {
                item->setParent(ui->Done_2);
                item->move(5,5);
                item->show();
            }else{
                item->move(5,5);
            }
}
