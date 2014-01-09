#ifndef WORKHISTORYCREATOR_H
#define WORKHISTORYCREATOR_H

#include "../TFS/RemainingWorkHistory.h"
#include "../TFS/SprintBacklogItem.h"

#include <vector>
using std::vector;

class WorkHistoryCreator
{
public:
    WorkHistoryCreator();
    vector<RemainingWorkHistory*> Create(vector<SprintBacklogItem*> sbis);
};

#endif // WORKHISTORYCREATOR_H
