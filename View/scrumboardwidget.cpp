#include "scrumboardwidget.h"
#include "ui_scrumboardwidget.h"
#include "itemui.h"
#include "laneui.h"
#include <QPainter>
#include "../sbinotstartedlistmodel.h"
#include "../itemmimedata.h"

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
