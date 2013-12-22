#ifndef SBILISTMODELFILTER_H
#define SBILISTMODELFILTER_H
#include <vector>
#include <string>
#include "qstring.h"

// forward declarations
class SprintBacklogItem;

class SBIListModelFilter {
public:
    virtual std::vector<SprintBacklogItem*> Filter(std::vector<SprintBacklogItem*> content, QString phrase) = 0;
};

#endif // SBILISTMODELFILTER_H
