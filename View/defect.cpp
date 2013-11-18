#include "defect.h"
#include "ui_defect.h"

Defect::Defect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Defect)
{
    ui->setupUi(this);
}

Defect::~Defect()
{
    delete ui;
}
