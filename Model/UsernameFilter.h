#ifndef USERNAMEFILTER_H
#define USERNAMEFILTER_H

#include "SBIListModelFilter.h"
#include "qstring.h"

class UsernameFilter : public SBIListModelFilter
{
public:
    virtual std::vector<SprintBacklogItem*> Filter(std::vector<SprintBacklogItem*> content, QString phrase);
};

#endif // USERNAMEFILTER_H
