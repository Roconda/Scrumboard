#include "sbi.h"
#include "ui_sbi.h"
#include "defect.h"
#include "../tfswrapper.h"

#include "../TFS/User.h"

#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>

SBI::SBI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SBI)
{
    ui->setupUi(this);

    madeUnsavedChanges = false;

    ui->le_remaining_hours->setInputMask("000");
    ui->le_completed_hours->setInputMask("000");


    connect(ui->le_title, SIGNAL(textEdited(const QString)),
            this, SLOT(onChangedTitle(const QString)));
    connect(ui->le_description, SIGNAL(textEdited(const QString)),
            this, SLOT(onChangedDescription(const QString)));

    connect(ui->le_remaining_hours, SIGNAL(textEdited(const QString)),
            this, SLOT(onChangedRemainingHours(const QString)));
    connect(ui->le_completed_hours, SIGNAL(textEdited(const QString)),
            this, SLOT(onChangedCompletedHours(const QString)));

    connect(ui->le_current_user, SIGNAL(textEdited(const QString)),
            this, SLOT(onChangedCurrentUser(const QString)));
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


void SBI::setTitle(QString title)
{
    ui->le_title->setText(title);
}

void SBI::setDescription(QString description)
{
    ui->le_description->setText(description);
}

void SBI::setRemainingHours(double hours)
{
    ui->le_remaining_hours->setText(QString("%1").arg(hours).trimmed());
}

void SBI::setCompletedHours(double hours)
{
    ui->le_completed_hours->setText(QString("%1").arg(hours).trimmed());
}

void SBI::setTotalHours(double hours)
{
    ui->le_total_hours->setText(QString("%1").arg(hours).trimmed());
}

void SBI::setStatus(QString status)
{
    ui->lbl_status_value->setText(status);
}

void SBI::setCurrentUser(QString currentUser)
{
    ui->le_current_user->setText(currentUser);
}

void SBI::setSBIItem(SprintBacklogItem *item)
{
    sbiItem = item;
}


void SBI::onChangedTitle(const QString &text)
{
    madeUnsavedChanges = true;
}

void SBI::onChangedDescription(const QString &text)
{
    madeUnsavedChanges = true;
}

void SBI::onChangedRemainingHours(const QString &text)
{
    madeUnsavedChanges = true;
}

void SBI::onChangedCompletedHours(const QString &text)
{
    madeUnsavedChanges = true;
}

void SBI::onChangedStatus(const QString &text)
{
    madeUnsavedChanges = true;
}

void SBI::onChangedCurrentUser(const QString &text)
{
    madeUnsavedChanges = true;
}

void SBI::on_buttonBox_accepted()
{
    saveData();
}

void SBI::on_buttonBox_rejected()
{
    if (madeUnsavedChanges)
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Gegevens gewijzigd!", "U heeft zojuist wijzigingen gemaakt.\n\nWilt u uw laatste wijzigingen opslaan?",
                                      QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            saveData();
        }
        else
        { }
    }
}


void SBI::saveData()
{
    sbiItem->setTitle(ui->le_title->text().toLocal8Bit());
    sbiItem->setDescription(ui->le_description->text().toLocal8Bit());
    sbiItem->setRemainingWork(atof(ui->le_remaining_hours->text().toLocal8Bit()));
    sbiItem->setCompletedWork(atof(ui->le_completed_hours->text().toLocal8Bit()));
    sbiItem->setBaselineWork(atof(ui->le_total_hours->text().toLocal8Bit()));

    User* user = User::withName(ui->le_current_user->text().toLocal8Bit());
    sbiItem->setUser(user);

    TFSWrapper::instance().saveSelectedProject();
}
