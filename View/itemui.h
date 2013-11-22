#ifndef ITEMUI_H
#define ITEMUI_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class ItemUI;
}

class ItemUI : public QWidget
{
    Q_OBJECT

public:
    explicit ItemUI(QWidget *parent = 0);
    void setModel(QString s);
    ~ItemUI();

private:
    Ui::ItemUI *ui;
    QDataWidgetMapper *mapper;

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

};

#endif // ITEMUI_H
