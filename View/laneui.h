#ifndef LANEUI_H
#define LANEUI_H

#include <QWidget>
#include <QMouseEvent>
#include <QAbstractListModel>
#include "itemui.h";

namespace Ui {
class LaneUI;
}

class LaneUI : public QWidget
{
    Q_OBJECT

public:
    explicit LaneUI(QWidget *parent = 0);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *);
    void addItem(ItemUI* item);
    void setModel(QAbstractListModel *model);

    ~LaneUI();

private:
    Ui::LaneUI *ui;
    QAbstractListModel *model;
};

#endif // LANEUI_H
