#include "laneui.h"
#include "ui_laneui.h"
#include "itemui.h"

LaneUI::LaneUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LaneUI)
{
    ui->setupUi(this);

}

LaneUI::~LaneUI()
{
    delete ui;
}

