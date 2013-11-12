#include "notstartedlane.h"
#include <QtGui>
#include "workitem.h"

WorkItem *wi;

NotStartedLane::NotStartedLane(QWidget *parent):
    LaneDelegate(parent)
{
    wi = new WorkItem(this);
}
