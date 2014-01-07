#ifndef SBILISTMODELFILTER_H
#define SBILISTMODELFILTER_H
#include <vector>
#include <string>
#include "qstring.h"

// forward declarations
class WorkItem;

class SBIListModelFilter {
public:
    virtual std::vector<WorkItem *> Filter(std::vector<WorkItem*> content, QString phrase) = 0;
};

#endif // SBILISTMODELFILTER_H
