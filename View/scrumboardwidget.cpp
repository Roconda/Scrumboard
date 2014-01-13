#include "scrumboardwidget.h"
#include "ui_scrumboardwidget.h"
#include "../model/sbilistmodel.h"
#include "laneui.h"

ScrumboardWidget::ScrumboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrumboardWidget)
{
    ui->setupUi(this);
    ScrumboardWidgetHandler::getInstance().setParent(this);

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

void ScrumboardWidget::Reload()
{
    model.Reload();
}

void ScrumboardWidget::ClearFilterOptions()
{
    model.ClearFilterOptions();
    model.Reload();
}

void ScrumboardWidget::FilterIt(int filter, QString phrase)
{
    if(filter != -1)
    {
        switch(filter)
        {
            case USERNAME:
                model.AddFilterOption(USERNAME, phrase);
                //model.Filter(USERNAME, phrase);
                break;
            case SBI_TITLE:
                model.AddFilterOption(SBI_TITLE, phrase);
                //model.Filter(SBI_TITLE, phrase);
                break;
            default:
                break;
        }
    }

    model.FilterIt();
}

void ScrumboardWidget::updateSprintData()
{
    ui->NotStarted->setModel(nullptr);
    ui->Started->setModel(nullptr);
    ui->toVerify->setModel(nullptr);
    ui->Done->setModel(nullptr);

    ui->NotStarted->setModel(&model);
    ui->Started->setModel(&model);
    ui->toVerify->setModel(&model);
    ui->Done->setModel(&model);
}

QString ScrumboardWidget::compareLane(LaneUI *lane){
    if(lane == ui->NotStarted){
        return QString("Not Started");
    }else if(lane == ui->Done){
        return QString("Done");
    }else if(lane == ui->Started){
        return QString("Started");
    }else if(lane == ui->toVerify){
        return QString("To Verify");
    }else{
        return QString("Undefined");
    }
}
