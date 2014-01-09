#ifndef SCRUMBOARDWIDGETHANDLER_H
#define SCRUMBOARDWIDGETHANDLER_H

#include "View/itemui.h"
#include "View/laneui.h"
#include "View/defectui.h"

class ScrumboardWidgetHandler
{
public:
    static ScrumboardWidgetHandler& getInstance()
            {
                static ScrumboardWidgetHandler    instance; // Guaranteed to be destroyed.
                                      // Instantiated on first use.
                return instance;
            }

    bool setStatusForItem(ItemUI* item, LaneUI* lane);
    bool setStatusForItem(DefectUI* item, LaneUI* lane);
    SprintBacklogItem* getSBIForID(int id);
    Defect* getDefectForID(int id);
    void setParent(QWidget *parent){
        this->parent = parent;
    }

private:
    QWidget *parent;
    bool acceptStatus(QString currentLane, QString toLane);
    void setItemDone(SprintBacklogItem* SBIitem);

    ScrumboardWidgetHandler() {};
    ScrumboardWidgetHandler(ScrumboardWidgetHandler const&);
    void operator=(ScrumboardWidgetHandler const&);
};

#endif // SCRUMBOARDWIDGETHANDLER_H
