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
    void accept();
    void reject();
    bool save();


};

#endif // ADDDEFECT_H
