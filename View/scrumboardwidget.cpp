#include "scrumboardwidget.h"
#include "ui_scrumboardwidget.h"
#include "../sbinotstartedlistmodel.h"

ScrumboardWidget::ScrumboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrumboardWidget)
{
    ui->setupUi(this);
    SBINotStartedListModel *model = new SBINotStartedListModel;
    ui->NotStarted->setModel(model);
}

ScrumboardWidget::~ScrumboardWidget()
{
    delete ui;
}
