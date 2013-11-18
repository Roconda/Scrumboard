#ifndef WORKITEM_H
#define WORKITEM_H

#include <QWidget>

class WorkItem : public QWidget
{
    Q_OBJECT
public:
    explicit WorkItem(QWidget *parent = 0);


private:
  QWidget *m_parent;

signals:
  void drawWidget(QPainter &qp);

public slots:
  void paintEvent(QPaintEvent *e);
  void mouseDoubleClickEvent(QMouseEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);
};

#endif // WORKITEM_H
