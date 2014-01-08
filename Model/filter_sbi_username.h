#ifndef FILTER_SBI_USERNAME_H
#define FILTER_SBI_USERNAME_H
#include "filteroption.h"

class Filter_SBI_Username : public FilterOption
{
public:
    Filter_SBI_Username(FilterDecorator* component);
    virtual void Filter(std::vector<WorkItem*>& content, QString phrase);
};

#endif // FILTER_SBI_USERNAME_H
