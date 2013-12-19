#ifndef STATUSTYPECREATOR_H
#define STATUSTYPECREATOR_H

#include <vector>
using std::vector;

#include "../TFS/StatusType.h"

class StatusTypeCreator
{
public:
    StatusTypeCreator();
    vector<StatusType*> Create();
};

#endif // STATUSTYPECREATOR_H
