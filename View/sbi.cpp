#include "sbi.h"
#include "ui_sbi.h"
#include "defect.h"

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
    /*
    Defect *defect = new Defect(this);
    defect->show();
    */
}

void SBI::setRemainingHours(double hours)
{
    ui->lbl_remaining_hours->setText(QString("Aantal resterende uren: %1").arg(hours));
}

void SBI::setCompletedHours(double hours)
{
    ui->lbl_completed_hours->setText(QString("Aantal voldane uren: %1").arg(hours));
}

void SBI::setTotalHours(double hours)
{
    ui->lbl_total_hours->setText(QString("Totaal aantal uren: %1").arg(hours));
}

void SBI::setStatus(QString status)
{
    this->status = status;
    ui->lbl_status->setText(QString("Status: %1").arg(status));
}

void SBI::setCurrentUser(QString currentUser)
{
    this->currentUser = currentUser;
    ui->lbl_current_user->setText(QString("Huidige user: %1").arg(currentUser));
}
