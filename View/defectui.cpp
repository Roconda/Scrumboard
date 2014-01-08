#include "defectui.h"
#include "ui_defectui.h"

#include "../itemmimedata.h"
#include "../scrumboardwidgethandler.h"

#include "../TFS/User.h"
#include "../TFS/Status.h"
#include "../TFS/StatusType.h"
#include "../TFS/Defect.h"

DefectUI::DefectUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DefectUI)
{
    ui->setupUi(this);

    // Enable events and set a shadow
    installEventFilter(this);
    shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(DefectUI::DEAULT_SHADOW_BLUR);

    setGraphicsEffect(shadow);
}

DefectUI::~DefectUI()
{
    delete ui;
}

bool DefectUI::eventFilter(QObject *object, QEvent *event){
        // hover events
        if(object==this && (event->type()==QEvent::Enter || event->type()==QEvent::Leave)) {
            if(event->type()==QEvent::Enter) {
                shadow->setBlurRadius(DefectUI::DEAULT_SHADOW_BLUR);
                this->setGraphicsEffect(shadow);
            }else
                shadow->setBlurRadius(DefectUI::HOVER_SHADOW_BLUR);
        }

        // move event
        if(object==this && (event->type()==QEvent::MouseMove)){
            QDrag *drag = new QDrag(this);
            ItemMimeData *mimeData = new ItemMimeData;
            mimeData->setDefectUI(this);
            drag->setMimeData(mimeData);
            QPixmap map = QWidget::grab(this->rect());
            drag->setPixmap(map);
            this->hide();
            if(!(drag->exec())){
                this->show();
            }

            shadow->setBlurRadius(DefectUI::DEAULT_SHADOW_BLUR);
        }

        // double click event


        return true;
}

void DefectUI::setTitle(QString s)
{
    ui->titleLabel->setText(s);
}

void DefectUI::setID(QString s)
{
    ui->idLabel->setText("#" + s);
}

void DefectUI::setUser(QString s)
{
    ui->userLabel->setText(s);
}

QString DefectUI::getID(){
    return ui->idLabel->text();
}
