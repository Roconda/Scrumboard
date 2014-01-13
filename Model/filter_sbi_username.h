#ifndef FILTER_SBI_USERNAME_H
#define FILTER_SBI_USERNAME_H
#include "FilterOption.h"

class Filter_SBI_Username : public FilterOption
{
public:
    Filter_SBI_Username(FilterDecorator* component, QString phrase);
    virtual void Filter(std::vector<WorkItem *>& content);
};

#endif // FILTER_SBI_USERNAME_H
