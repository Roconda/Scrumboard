#ifndef DEFECTUI_H
#define DEFECTUI_H

#include <QWidget>

#include <QDrag>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QObject>

namespace Ui {
class DefectUI;
}

class DefectUI : public QWidget
{
    Q_OBJECT

public:
    explicit DefectUI(QWidget *parent = 0);
    ~DefectUI();
    void setTitle(QString s);
    void setID(QString s);
    void setUser(QString s);
    QString getID();

private:
    Ui::DefectUI *ui;
    QGraphicsDropShadowEffect* shadow;
    static const signed short DEAULT_SHADOW_BLUR = 5;
    static const signed short HOVER_SHADOW_BLUR = 15;

protected:
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // DEFECTUI_H
