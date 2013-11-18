#ifndef LANEUI_H
#define LANEUI_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class LaneUI;
}

class LaneUI : public QWidget
{
    Q_OBJECT

public:
    explicit LaneUI(QWidget *parent = 0);
    ~LaneUI();

private:
    Ui::LaneUI *ui;
};

#endif // LANEUI_H
