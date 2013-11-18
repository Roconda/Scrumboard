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

public slots:

};

#endif // WORKITEM_H
