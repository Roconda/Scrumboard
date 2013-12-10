#ifndef SCRUMBOARDWIDGETHANDLER_H
#define SCRUMBOARDWIDGETHANDLER_H

#include "View/itemui.h"
#include "View/laneui.h"

class ScrumboardWidgetHandler
{
public:
    static ScrumboardWidgetHandler& getInstance()
            {
                static ScrumboardWidgetHandler    instance; // Guaranteed to be destroyed.
                                      // Instantiated on first use.
                return instance;
            }

    void setStatusForSBI(ItemUI* item, LaneUI* lane);
    void setParent(QWidget *parent){
        this->parent = parent;
    }

private:
    QWidget *parent;

    ScrumboardWidgetHandler() {};
    ScrumboardWidgetHandler(ScrumboardWidgetHandler const&);
    void operator=(ScrumboardWidgetHandler const&);
};

#endif // SCRUMBOARDWIDGETHANDLER_H
