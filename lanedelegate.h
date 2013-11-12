#ifndef LANEDELEGATE_H
#define LANEDELEGATE_H

#include <QWidget>

class LaneDelegate : public QWidget
{
    Q_OBJECT
public:
    explicit LaneDelegate(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);
    void drawWidget(QPainter &qp);

private:

signals:

public slots:

};

#endif // LANEDELEGATE_H
