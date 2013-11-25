#include "laneui.h"
#include "ui_laneui.h"
#include "itemui.h"
#include "../itemmimedata.h"

LaneUI::LaneUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LaneUI)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

LaneUI::~LaneUI()
{
    delete ui;
}

void LaneUI::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void LaneUI::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void LaneUI::dropEvent(QDropEvent *event)
{
    event->setDropAction(Qt::MoveAction);
    ItemMimeData* data = (ItemMimeData*) event->mimeData();
    ItemUI* item = data->getItemUI();
    item->setParent(this);
    this->layout()->addWidget(item);
    item->show();
    event->accept();
}

void LaneUI::addItem(ItemUI *item){
    item->setParent(this);
}

void LaneUI::setModel(QAbstractListModel *model){
    this->model = model;
    int i =0;
    for(i; i < model->rowCount(); i++){
        ItemUI *it = new ItemUI(this);
        it->setTitle(model->data(model->index(i,0), Qt::UserRole).toString());
        it->setDescription(model->data(model->index(i,0), Qt::UserRole + 1).toString());
        it->setID(model->data(model->index(i,0), Qt::UserRole + 2).toString());
        ui->gridLayout->addWidget(it);
    }

}
