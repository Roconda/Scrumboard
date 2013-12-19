#ifndef PROJECTCREATOR_H
#define PROJECTCREATOR_H

#include "../TFS/TFSTransaction.h"
#include "../TFS/Project.h"

class ProjectCreator
{
public:
    ProjectCreator();
    Project* Create();
};

#endif // PROJECTCREATOR_H
