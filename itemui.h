#ifndef ITEMUI_H
#define ITEMUI_H

#include <QWidget>

namespace Ui {
class ItemUI;
}

class ItemUI : public QWidget
{
    Q_OBJECT

public:
    explicit ItemUI(QWidget *parent = 0);
    ~ItemUI();

private:
    Ui::ItemUI *ui;

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // ITEMUI_H
