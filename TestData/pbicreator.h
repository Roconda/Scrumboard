#ifndef PBICREATOR_H
#define PBICREATOR_H

#include "../TFS/ProductBacklogItem.h"
#include "../TFS/Sprint.h"

#include <vector>
using std::vector;

class PBICreator
{
public:
    PBICreator();
    vector<ProductBacklogItem*> Create(vector<Sprint*> sprints);
};

#endif // PBICREATOR_H
