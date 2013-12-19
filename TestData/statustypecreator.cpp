#include "statustypecreator.h"

StatusTypeCreator::StatusTypeCreator()
{
}

vector<StatusType*> StatusTypeCreator::Create()
{
    vector<StatusType*> statusTypes;

    statusTypes.push_back(StatusType::withName("Not Started"));
    statusTypes.push_back(StatusType::withName("Started"));
    statusTypes.push_back(StatusType::withName("To Verify"));
    statusTypes.push_back(StatusType::withName("Done"));

    statusTypes[0]->addNextStatusType(*statusTypes[1]);
    statusTypes[1]->addNextStatusType(*statusTypes[2]);
    statusTypes[2]->addNextStatusType(*statusTypes[3]);

    return statusTypes;
}
