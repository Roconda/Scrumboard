#include "adddefect.h"
#include "ui_adddefect.h"

AddDefect::AddDefect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDefect)
{
    ui->setupUi(this);
}

AddDefect::~AddDefect()
{
    delete ui;
}
