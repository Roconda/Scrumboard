#ifndef SPRINTCREATOR_H
#define SPRINTCREATOR_H

#include <vector>
using std::vector;

#include "../TFS/Project.h"
#include "../TFS/Sprint.h"

class SprintCreator
{
public:
    SprintCreator();
    vector<Sprint*> Create(Project* project);
};

#endif // SPRINTCREATOR_H
