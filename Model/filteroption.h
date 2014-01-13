#ifndef FILTEROPTION_H
#define FILTEROPTION_H
#include "filterdecorator.h"

#include <QString>
#include <vector>

#include "../TFS/WorkItem.h"

class FilterOption : public FilterDecorator
{
public:
    protected:
        FilterDecorator* component;
        QString phrase;

    public:
        FilterOption(FilterDecorator* component, QString phrase);
        virtual void Filter(std::vector<WorkItem *>& content) = 0;
};

#endif // FILTEROPTION_H
