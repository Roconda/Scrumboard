#include "scrumboardwidget.h"
#include "ui_scrumboardwidget.h"
#include "../sbilistmodel.h"
#include "laneui.h"

ScrumboardWidget::ScrumboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrumboardWidget)
{
    ui->setupUi(this);
    SBIListModel model;

    ui->NotStarted->setDisplayRole(SBIDisplayRoles::NotStarted);
    ui->Started->setDisplayRole(SBIDisplayRoles::Started);
    ui->toVerify->setDisplayRole(SBIDisplayRoles::ToVerify);
    ui->Done->setDisplayRole(SBIDisplayRoles::Done);

    ui->NotStarted->setModel(&model);
    ui->Started->setModel(&model);
    ui->toVerify->setModel(&model);
    ui->Done->setModel(&model);
}

ScrumboardWidget::~ScrumboardWidget()
{
    delete ui;
}

void ScrumboardWidget::updateSprintData()
{
    SBIListModel model;
    //ui->NotStarted->setModel(&model);
}
