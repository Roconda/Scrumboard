#ifndef SBI_TITLEFILTER_H
#define SBI_TITLEFILTER_H

#include "SBIListModelFilter.h"
#include "qstring.h"

class SBI_TitleFilter : public SBIListModelFilter
{
public:
    virtual std::vector<SprintBacklogItem*> Filter(std::vector<SprintBacklogItem*> content, QString phrase);
};

#endif // SBI_TITLEFILTER_H
