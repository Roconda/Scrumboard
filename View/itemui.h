#ifndef ITEMUI_H
#define ITEMUI_H

#include "../TFS/SprintBacklogItem.h"

#include <QWidget>
#include <QDataWidgetMapper>
#include <QGraphicsDropShadowEffect>
#include <QEvent>
#include <QObject>

namespace Ui {
class ItemUI;
}

class ItemUI : public QWidget
{
    Q_OBJECT

public:
    explicit ItemUI(QWidget *parent = 0);
    void setTitle(QString s);
    void setID(QString s);
    void setRemainingHours(QString s);
    void setPriority(QString s);
    void setUser(QString s);
    QString getID();
    ~ItemUI();

private:
    Ui::ItemUI *ui;
    QDataWidgetMapper *mapper;
    QGraphicsDropShadowEffect* shadow;
    static const signed short DEAULT_SHADOW_BLUR = 5;
    static const signed short HOVER_SHADOW_BLUR = 15;

protected:
    bool eventFilter(QObject *object, QEvent *event);

protected slots:
    void updateItem(SprintBacklogItem *sbiItem);
};

#endif // ITEMUI_H
