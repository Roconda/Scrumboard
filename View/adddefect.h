#ifndef ADDDEFECT_H
#define ADDDEFECT_H

#include <QDialog>

namespace Ui {
class AddDefect;
}

class AddDefect : public QDialog
{
    Q_OBJECT

public:
    explicit AddDefect(QWidget *parent = 0);
    ~AddDefect();

private:
    Ui::AddDefect *ui;
};

#endif // ADDDEFECT_H
