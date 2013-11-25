#include "itemui.h"
#include "ui_itemui.h"
#include "sbi.h"
#include <QMouseEvent>
#include "../itemhandler.h"
#include <QDrag>
#include "../itemmimedata.h"

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
    SBI *sbi1 = new SBI();
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

void ItemUI::setModel(QString s){
    ui->label->setText(s);
}
