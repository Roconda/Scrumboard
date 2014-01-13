#ifndef SCRUMBOARDWIDGET_H
#define SCRUMBOARDWIDGET_H

#include <QWidget>
#include "../scrumboardwidgethandler.h"

namespace Ui {
class ScrumboardWidget;
}

class ScrumboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScrumboardWidget(QWidget *parent = 0);
    ~ScrumboardWidget();
    void Reload();
    void updateSprintData();
    void FilterIt(int filter = -1, QString phrase = NULL);
    void ClearFilterOptions();
    QString compareLane(LaneUI *);

private:
    Ui::ScrumboardWidget *ui;
    ScrumboardWidgetHandler *handler;

    SBIListModel model;
};

#endif // SCRUMBOARDWIDGET_H
