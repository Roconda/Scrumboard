#ifndef LANEUI_H
#define LANEUI_H

#include <QWidget>
#include <QMouseEvent>
#include <QAbstractListModel>

namespace Ui {
class LaneUI;
}

class ItemUI;

class LaneUI : public QWidget
{
    Q_OBJECT

public:
    explicit LaneUI(QWidget *parent = 0);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *);
    void setModel(QAbstractListModel *model);

    ~LaneUI();

private:
    Ui::LaneUI *ui;
    QAbstractListModel *model;
};

#endif // LANEUI_H
