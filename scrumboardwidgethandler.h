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

    bool setStatusForSBI(ItemUI* item, LaneUI* lane);
    SprintBacklogItem* getItemForID(int* id);
    void setParent(QWidget *parent){
        this->parent = parent;
    }

private:
    QWidget *parent;
    bool acceptStatus(QString currentLane, QString toLane);

    ScrumboardWidgetHandler() {};
    ScrumboardWidgetHandler(ScrumboardWidgetHandler const&);
    void operator=(ScrumboardWidgetHandler const&);
};

#endif // SCRUMBOARDWIDGETHANDLER_H
