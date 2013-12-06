#include "laneui.h"
#include "ui_laneui.h"
#include "itemui.h"
#include "../itemmimedata.h"
#include "../sbilistmodel.h"

LaneUI::LaneUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LaneUI),
    displayrole(SBIDisplayRoles::NotStarted)
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
    if(item->parentWidget() != this){
        item->setParent(this);
        this->layout()->addWidget(item);
    }
    item->show();
    event->accept();
}

void LaneUI::setDisplayRole(SBIDisplayRoles::SBIDisplayRoles displayrole)
{
    this->displayrole = displayrole;
}

void LaneUI::setModel(QAbstractListModel *model){
    this->model = model;

    // TODO clear current widgets

    for(int i = 0; i < model->rowCount(); i++){
        QVariant sbiDataVariant = model->data(model->index(i,0), this->displayrole);
        if (sbiDataVariant == QVariant())
            continue;

        QMap<QString, QVariant> sbiData = sbiDataVariant.toMap();

        ItemUI *it = new ItemUI(this);
        it->setTitle(sbiData.find("Title")->toString());
        it->setID(sbiData.find("WorkItemNumber")->toString());
        it->setRemainingHours(sbiData.find("RemainingHours")->toString());
        it->setPriority(sbiData.find("Priority")->toString());
        it->setUser(sbiData.find("UserName")->toString());

        ui->gridLayout->addWidget(it);
    }

}
