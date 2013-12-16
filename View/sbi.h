#ifndef SBI_H
#define SBI_H

#include <QDialog>

namespace Ui {
class SBI;
}

class SBI : public QDialog
{
    Q_OBJECT

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

private slots:
    void on_pushButton_clicked();

private:
    Ui::SBI *ui;

    double remainingHours;
    double completedHours;
    double totalHours;

    QString status;
    QString currentUser;
};

#endif // SBI_H
