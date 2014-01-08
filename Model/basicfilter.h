#ifndef BASICFILTER_H
#define BASICFILTER_H
#include "filterdecorator.h"

class BasicFilter : public FilterDecorator
{
public:
    BasicFilter();
    virtual void Filter(std::vector<WorkItem*>& content, QString phrase);
};

#endif // BASICFILTER_H
