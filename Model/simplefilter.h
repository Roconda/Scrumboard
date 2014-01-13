#ifndef SIMPLEFILTER_H
#define SIMPLEFILTER_H

#include "filterdecorator.h"

#include "../TFS/WorkItem.h"

#include <vector>

class SimpleFilter : public FilterDecorator
{
public:
    SimpleFilter();
    virtual void Filter(std::vector<WorkItem *> &content);
};

#endif // SIMPLEFILTER_H
