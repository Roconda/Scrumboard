#include "sbi.h"
#include "ui_sbi.h"
#include "../tfswrapper.h"
#include "scrumboardwidget.h"

#include "../TFS/User.h"

#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>

/**
 * @brief SBI::SBI      Initializes a new instance of the SBI UI.
 * @param parent        This Dialog's parent.
 */
SBI::SBI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SBI)
{
    ui->setupUi(this);

    madeUnsavedChanges = false;

    ui->le_remaining_hours->setInputMask("000");
    ui->le_completed_hours->setInputMask("000");


    //Connect window events to handler methods
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

/**
 * @brief SBI::~SBI     Class destructor
 */
SBI::~SBI()
{
    delete ui;
}


void SBI::on_pushButton_clicked()
{

}


/**
 * @brief SBI::setTitle             Sets the title for the current selected SBI item.
 * @param title                     The new title for the current selected SBI item.
 */
void SBI::setTitle(QString title)
{
    ui->le_title->setText(title);
}

/**
 * @brief SBI::setDescription       Sets the description for the current selected SBI item.
 * @param description               The new description for the current selected SBI item.
 */
void SBI::setDescription(QString description)
{
    ui->le_description->setText(description);
}

/**
 * @brief SBI::setRemainingHours    Sets the remaining working hours for the current selected SBI item.
 * @param hours                     The new remaining working hours value for the current selected SBI item.
 */
void SBI::setRemainingHours(double hours)
{
    ui->le_remaining_hours->setText(QString("%1").arg(hours).trimmed());
}

/**
 * @brief SBI::setCompletedHours    Sets the completed working hours for the current selected SBI item.
 * @param hours                     The new completed working hours value for the current selected SBI item.
 */
void SBI::setCompletedHours(double hours)
{
    ui->le_completed_hours->setText(QString("%1").arg(hours).trimmed());
}

/**
 * @brief SBI::setTotalHours        Sets the total working hours for the current selected SBI item.
 * @param hours                     The new total working hours value for the current selected SBI item.
 */
void SBI::setTotalHours(double hours)
{
    ui->le_total_hours->setText(QString("%1").arg(hours).trimmed());
}

/**
 * @brief SBI::setStatus            Sets the status for the current selected SBI item.
 * @param status                    The new status for the current selected SBI item.
 */
void SBI::setStatus(QString status)
{
    ui->lbl_status_value->setText(status);
}

/**
 * @brief SBI::setCurrentUser       Sets the current user for the current selected SBI item.
 * @param currentUser               The new current user for the current selected SBI item.
 */
void SBI::setCurrentUser(QString currentUser)
{
    ui->le_current_user->setText(currentUser);
}

/**
 * @brief SBI::setSBIItem           Sets the current selected SBI item for this dialog.
 * @param item                      The new current selected SBI item for this dialog.
 */
void SBI::setSBIItem(SprintBacklogItem *item)
{
    sbiItem = item;
}


/**
 * @brief SBI::onChangedTitle           Handles the unsaved changes event after the title has been changed.
 * @param text                          Event arguments for the changed title.
 */
void SBI::onChangedTitle(const QString &text)
{
    madeUnsavedChanges = true;
}

/**
 * @brief SBI::onChangedDescription     Handles the unsaved changes event after the description has been changed.
 * @param text                          Event arguments for the changed description.
 */
void SBI::onChangedDescription(const QString &text)
{
    madeUnsavedChanges = true;
}

/**
 * @brief SBI::onChangedRemainingHours  Handles the unsaved changes event after the remaining working hours value has been changed.
 * @param text                          Event arguments for the changed remaining working hours value.
 */
void SBI::onChangedRemainingHours(const QString &text)
{
    madeUnsavedChanges = true;
}

/**
 * @brief SBI::onChangedCompletedHours  Handles the unsaved changes event after the completed working hours value has been changed.
 * @param text                          Event arguments for the changed completed working hours value.
 */
void SBI::onChangedCompletedHours(const QString &text)
{
    madeUnsavedChanges = true;
}

/**
 * @brief SBI::onChangedCurrentUser     Handles the unsaved changes event after the current user has been changed.
 * @param text                          Event arguments for the changed current user.
 */
void SBI::onChangedCurrentUser(const QString &text)
{
    madeUnsavedChanges = true;
}

/**
 * @brief SBI::on_buttonBox_accepted    On click event for the OK button of this dialog.
 */
void SBI::on_buttonBox_accepted()
{
    saveData();
    onChangedDetails(sbiItem);
}

/**
 * @brief SBI::on_buttonBox_rejected    On click event for the cancel button of this dialog.
 */
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
        { /* Ignore saving the changes that were made */ }
    }

    onChangedDetails(sbiItem);
}


/**
 * @brief SBI::saveData                 Saves all changes that were made in the details.
 */
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
