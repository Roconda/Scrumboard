#include "laneui.h"
#include "ui_laneui.h"
#include "itemui.h"
#include "defectui.h"
#include "../itemmimedata.h"
#include "../model/sbilistmodel.h"
#include "scrumboardwidget.h"

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
    DefectUI* defect = data->getDefectUI();

    if(item){
        if(item->parentWidget() != this){
            if(ScrumboardWidgetHandler::getInstance().setStatusForItem(item, this)){
                item->setParent(this);
                this->layout()->addWidget(item);
            }
        }else{
            event->ignore();
            item->show();
            return;
        }
        item->show();
    }else if(defect){
        if(defect->parentWidget() != this){
            if(ScrumboardWidgetHandler::getInstance().setStatusForItem(defect, this)){
                defect->setParent(this);
                this->layout()->addWidget(defect);
            }
        }else{
            event->ignore();
            defect->show();
            return;
        }
        defect->show();
    }
    event->accept();
}

void LaneUI::setDisplayRole(SBIDisplayRoles::SBIDisplayRoles displayrole)
{
    this->displayrole = displayrole;
}

void LaneUI::setModel(QAbstractListModel *model){
    this->model = model;

    //recursively deletes children and their childeren.
    QList<ItemUI *> itemwidgets = findChildren<ItemUI *>();
    foreach(ItemUI * widget, itemwidgets)
    {
        delete widget;
    }

    QList<DefectUI *> defectwidgets = findChildren<DefectUI *>();
    foreach(DefectUI * widget, defectwidgets)
    {
        delete widget;
    }

    for(int i = 0; i < model->rowCount(); i++){
        QVariant sbiDataVariant = model->data(model->index(i,0), this->displayrole);
        if (sbiDataVariant == QVariant())
            continue;

        QMap<QString, QVariant> sbiData = sbiDataVariant.toMap();

        if(sbiData.find("isDefect")->toString() == QString("False")){
            ItemUI *it = new ItemUI(this);
            it->setTitle(sbiData.find("Title")->toString());
            it->setID(sbiData.find("WorkItemNumber")->toString());
            it->setRemainingHours(sbiData.find("RemainingHours")->toString());
            it->setUser(sbiData.find("UserName")->toString());
            it->setPriority(sbiData.find("Priority")->toString());
            ui->gridLayout->addWidget(it);
            it->show();
            it->repaint();
        }else{
            DefectUI *def = new DefectUI(this);
            def->setTitle(sbiData.find("Title")->toString());
            def->setID(sbiData.find("WorkItemNumber")->toString());
            def->setUser(sbiData.find("UserName")->toString());
            ui->gridLayout->addWidget(def);
            def->show();
            def->repaint();
        }
    }
}
