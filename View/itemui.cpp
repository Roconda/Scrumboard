#include "itemui.h"
#include "ui_itemui.h"
#include "sbi.h"
#include "../itemmimedata.h"
#include "../scrumboardwidgethandler.h"
#include "../TFS/User.h"
#include "../TFS/Status.h"
#include "../TFS/StatusType.h"
#include "../TFS/SprintBacklogItem.h"

#include <QDrag>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QDebug>


ItemUI::ItemUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemUI)
{
    ui->setupUi(this);

    // Enable events and set a shadow
    installEventFilter(this);
    shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(ItemUI::DEAULT_SHADOW_BLUR);

    setGraphicsEffect(shadow);
}

ItemUI::~ItemUI()
{
    delete ui;
}

bool ItemUI::eventFilter(QObject *object, QEvent *event){
        // hover events
        if(object==this && (event->type()==QEvent::Enter || event->type()==QEvent::Leave)) {
            if(event->type()==QEvent::Enter) {
                shadow->setBlurRadius(ItemUI::DEAULT_SHADOW_BLUR);
                this->setGraphicsEffect(shadow);
            }else
                shadow->setBlurRadius(ItemUI::HOVER_SHADOW_BLUR);
        }

        // move event
        if(object==this && (event->type()==QEvent::MouseMove)){
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
            shadow->setBlurRadius(ItemUI::DEAULT_SHADOW_BLUR);
        }

        // double click event
        if (object == this && (event->type()==QEvent::MouseButtonDblClick)) {
            SBI *sbi = new SBI(this);


            QString itemID = ui->idLabel->text();
            itemID.remove(0, 1);

            SprintBacklogItem* currentItem = ScrumboardWidgetHandler::getInstance().getItemForID(itemID.toInt());
            if (currentItem) {
                sbi->setPoints(currentItem->getCompletedWork());
                sbi->setHours(currentItem->getRemainingWork());

                sbi->setStatus(currentItem->getStatus(itemID.toInt())->getStatusType()->getName());
                sbi->setCurrentUser(currentItem->getUser()->getName());

                sbi->exec();
            } else {
                qDebug() << "Cannot find item!";
            }
        }

        return true;
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
void ItemUI::setPriority(QString s) {
    ui->priorityLabel->setText(s);
}

QString ItemUI::getID(){
    return ui->idLabel->text();
}
