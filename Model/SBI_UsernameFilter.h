#ifndef SBI_USERNAMEFILTER_H
#define SBI_USERNAMEFILTER_H

#include "SBIListModelFilter.h"
#include "qstring.h"

class SBI_UsernameFilter : public SBIListModelFilter
{
public:
    virtual std::vector<SprintBacklogItem*> Filter(std::vector<SprintBacklogItem*> content, QString phrase);
};

#endif // SBI_USERNAMEFILTER_H
