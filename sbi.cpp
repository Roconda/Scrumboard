#include "View/sbi.h"
#include "ui_sbi.h"

SBI::SBI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SBI)
{
    ui->setupUi(this);
}

SBI::~SBI()
{
    delete ui;
}

void SBI::on_pushButton_clicked()
{
//    Defect *defect = new Defect(this);
//    defect->show();
}
