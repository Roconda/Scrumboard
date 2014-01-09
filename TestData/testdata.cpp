#include "testdata.h"

TestData::TestData()
{
    // Delete all data from server.
    TFSTransaction::removeAllData();

    // Create the project
    Project* project = projectCreator.Create();
    // Create the users
    vector<User*> users = userCreator.Create();
    // Create the statusTypes
    vector<StatusType*> statusTypes = statusTypeCreator.Create();
    // Create the sprints
    vector<Sprint*> sprints = sprintCreator.Create(project);
    // Create the pbi's
    vector<ProductBacklogItem*> pbis = pbiCreator.Create(sprints);
    // Create the sbi's
    vector<SprintBacklogItem*> sbis = sbiCreator.Create(users, statusTypes, pbis, sprints);
    // Set the remaining work history
    vector<RemainingWorkHistory*> histories = remainingWorkHistoryCreator.Create(sbis);

    // Send the contents of the project to the server.
    TFSTransaction::remoteWriteProject("Scrumbag");
}
