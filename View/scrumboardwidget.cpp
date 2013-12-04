#include "scrumboardwidget.h"
#include "ui_scrumboardwidget.h"
#include "../sbilistmodel.h"

ScrumboardWidget::ScrumboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrumboardWidget)
{
    ui->setupUi(this);
    SBIListModel model;

    ui->NotStarted->setModel(&model);
}

ScrumboardWidget::~ScrumboardWidget()
{
    delete ui;
}

void ScrumboardWidget::updateSprintData()
{
    SBIListModel model;
    ui->NotStarted->setModel(&model);
}
