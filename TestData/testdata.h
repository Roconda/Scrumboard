#ifndef TESTDATA_H
#define TESTDATA_H

#include <vector>
using std::vector;

#include "projectcreator.h"
#include "usercreator.h"
#include "statustypecreator.h"
#include "sprintcreator.h"
#include "pbicreator.h"
#include "sbicreator.h"
#include "workhistorycreator.h"

class TestData
{
private:
    ProjectCreator projectCreator;
    UserCreator userCreator;
    StatusTypeCreator statusTypeCreator;
    SprintCreator sprintCreator;
    PBICreator pbiCreator;
    SBICreator sbiCreator;
    WorkHistoryCreator remainingWorkHistoryCreator;


public:
    TestData();
};

#endif // TESTDATA_H
