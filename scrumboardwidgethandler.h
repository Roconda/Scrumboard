#ifndef SCRUMBOARDWIDGETHANDLER_H
#define SCRUMBOARDWIDGETHANDLER_H

#include "View/itemui.h"
#include "View/laneui.h"

class ScrumboardWidgetHandler
{
public:
    explicit ScrumboardWidgetHandler(QWidget *parent = 0);
    static void setStatusForSBI(ItemUI* item, LaneUI* lane);

private:
    static QWidget *parent;
};

#endif // SCRUMBOARDWIDGETHANDLER_H
