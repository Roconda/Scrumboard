#ifndef SBICREATOR_H
#define SBICREATOR_H

#include "../TFS/SprintBacklogItem.h"
#include "../TFS/Status.h"
#include "../TFS/User.h"
#include "../TFS/StatusType.h"
#include "../TFS/ProductBacklogItem.h"
#include "../TFS/Sprint.h"

#include <vector>
using std::vector;

class SBICreator
{
public:
    SBICreator();
    vector<SprintBacklogItem*> Create(vector<User*> users, vector<StatusType*> statusTypes, vector<ProductBacklogItem*> pbis, vector<Sprint*> sprints);
};

#endif // SBICREATOR_H
