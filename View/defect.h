#ifndef DEFECT_H
#define DEFECT_H

#include <QDialog>


namespace Ui {
class Defect;
}

class Defect : public QDialog
{
    Q_OBJECT

public:
    explicit Defect(QWidget *parent = 0);
    ~Defect();

private:
    Ui::Defect *ui;
};

#endif // DEFECT_H
