#include "notstartedlane.h"
#include <QtGui>
#include "itemui.h"

ItemUI *wi;

NotStartedLane::NotStartedLane(QWidget *parent):
    LaneDelegate(parent)
{
    wi = new ItemUI(this);
}
