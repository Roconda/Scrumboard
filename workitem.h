#ifndef WORKITEM_H
#define WORKITEM_H

#include <QWidget>

class WorkItem : public QWidget
{
    Q_OBJECT
public:
    explicit WorkItem(QWidget *parent = 0);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent *e);
    void drawWidget(QPainter &qp);

private:
  QWidget *m_parent;

signals:

public slots:

};

#endif // WORKITEM_H
