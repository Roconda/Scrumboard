#ifndef FILTER_SBI_TITLE_H
#define FILTER_SBI_TITLE_H
#include "FilterOption.h"

class Filter_SBI_Title : public FilterOption
{
public:
    Filter_SBI_Title(FilterDecorator* component, QString phrase);
    virtual void Filter(std::vector<WorkItem *>& content);
};

#endif // FILTER_SBI_TITLE_H
