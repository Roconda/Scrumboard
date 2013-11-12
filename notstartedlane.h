#ifndef NOTSTARTEDLANE_H
#define NOTSTARTEDLANE_H

#include "lanedelegate.h"

class NotStartedLane : public LaneDelegate
{
public:
    explicit NotStartedLane(QWidget *parent = 0);

protected:
};

#endif // NOTSTARTEDLANE_H
