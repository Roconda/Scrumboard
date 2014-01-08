#ifndef FILTEROPTION_H
#define FILTEROPTION_H
#include "filterdecorator.h"

class FilterOption : public FilterDecorator
{
private:
    FilterDecorator* component;

public:
    FilterOption(FilterDecorator* component);
    virtual void Filter(std::vector<WorkItem*>& content, QString phrase) = 0;
};

#endif // FILTEROPTION_H
