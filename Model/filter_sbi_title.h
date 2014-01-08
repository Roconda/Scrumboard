#ifndef FILTER_SBI_TITLE_H
#define FILTER_SBI_TITLE_H
#include "filteroption.h"

class Filter_SBI_Title : public FilterOption
{
public:
    Filter_SBI_Title(FilterDecorator* component);
    virtual void Filter(std::vector<WorkItem*>& content, QString phrase);
};

#endif // FILTER_SBI_TITLE_H
