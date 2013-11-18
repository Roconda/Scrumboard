#include "scrumboardwidget.h"
#include "ui_scrumboardwidget.h"
#include "itemui.h"

ScrumboardWidget::ScrumboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScrumboardWidget)
{
    ui->setupUi(this);
    ItemUI *wi;
    wi = new ItemUI(ui->ToVerify_2);
    wi->setParent(this);

}

ScrumboardWidget::~ScrumboardWidget()
{
    delete ui;
}
