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

private slots:
    void on_pushButton_clicked();

private:
    Ui::SBI *ui;
};

#endif // SBI_H