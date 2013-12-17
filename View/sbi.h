#ifndef SBI_H
#define SBI_H

#include <QDialog>

#include "../TFS/SprintBacklogItem.h"

namespace Ui {
class SBI;
}

class SBI : public QDialog
{
    Q_OBJECT

private:
    void saveData();

public:
    explicit SBI(QWidget *parent = 0);
    ~SBI();

    void setTitle(QString title);
    void setDescription(QString description);

    void setRemainingHours(double hours);
    void setCompletedHours(double hours);
    void setTotalHours(double hours);

    void setStatus(QString status);
    void setCurrentUser(QString currentUser);

    void setSBIItem(SprintBacklogItem* item);

protected slots:
    void onChangedTitle(const QString &text);
    void onChangedDescription(const QString &text);
    void onChangedRemainingHours(const QString &text);
    void onChangedCompletedHours(const QString &text);
    void onChangedStatus(const QString &text);
    void onChangedCurrentUser(const QString &text);

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SBI *ui;

    SprintBacklogItem* sbiItem;

    bool madeUnsavedChanges;
};

#endif // SBI_H
