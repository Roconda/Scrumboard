#include "itemui.h"
#include "ui_itemui.h"
#include "sbi.h"
#include "../itemmimedata.h"

#include <QDrag>
#include <QMouseEvent>


ItemUI::ItemUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemUI)
{
    ui->setupUi(this);
}

ItemUI::~ItemUI()
{
    delete ui;
}

void ItemUI::mouseDoubleClickEvent(QMouseEvent *event){
    SBI *sbi1 = new SBI(this);
    sbi1->exec();
}

void ItemUI::mouseMoveEvent(QMouseEvent *event)
{
    QDrag *drag = new QDrag(this);
    ItemMimeData *mimeData = new ItemMimeData;
    mimeData->setItemUI(this);
    drag->setMimeData(mimeData);
    QPixmap map = QWidget::grab(this->rect());
    drag->setPixmap(map);
    this->hide();
    if(!(drag->exec())){
        this->show();
    }
}

void ItemUI::setTitle(QString s)
{
    ui->titleLabel->setText(s);
}

void ItemUI::setID(QString s)
{
    ui->idLabel->setText("#" + s);
}
void ItemUI::setRemainingHours(QString s)
{
    ui->hoursLabel->setText(s + " uur");
}
void ItemUI::setUser(QString s)
{
    ui->userLabel->setText(s);
}
