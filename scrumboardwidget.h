#ifndef SCRUMBOARDWIDGET_H
#define SCRUMBOARDWIDGET_H

#include <QWidget>

namespace Ui {
class ScrumboardWidget;
}

class ScrumboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScrumboardWidget(QWidget *parent = 0);
    ~ScrumboardWidget();

private:
    Ui::ScrumboardWidget *ui;
};

#endif // SCRUMBOARDWIDGET_H
