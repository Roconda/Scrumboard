#include <iostream>

#include "tfswrapper.h"
#include "TFS/TFSTransaction.h"
#include "TFS/Project.h"
#include "TFS/Sprint.h"
#include "TFS/StatusType.h"
#include "TFS/User.h"


#include "createtestdata.h"

using std::cout;

TFSWrapper::TFSWrapper() : selectedSprint(0)
{
    //CreateTestData t;

    // FIXME zorg voor project kies functionaliteit.
    this->selectedProject = TFSTransaction::remoteReadProject("Sinterklaas Package Distribution Software");
    this->selectedUser = this->getSelectedUser();
}

Project *TFSWrapper::getSelectedProject()
{
    return this->selectedProject;
}

void TFSWrapper::saveSelectedProject()
{
    TFSTransaction::remoteWriteProject("Sinterklaas Package Distribution Software");
}

Sprint *TFSWrapper::setSelectedSprint(size_t index)
{
    this->selectedSprint = index;
    return getSelectedSprint();
}

size_t TFSWrapper::getSelectedSprintIndex()
{
    return this->selectedSprint;
}

Sprint *TFSWrapper::getSelectedSprint()
{
    if (this->selectedProject)
        return this->selectedProject->getSprint(this->selectedSprint);
    else
        return nullptr;
}

User *TFSWrapper::getSelectedUser()
{
    // check if nullpointer, otherwise set the first User as default
    if(selectedUser == nullptr) {
        User::ItemStorage::iterator iType;
        for(iType = User::getStorage().begin(); iType != User::getStorage().end(); ++iType){
            std::pair<std::string, User*> pair = *iType;
            selectedUser = pair.second;
        }
    }

    return selectedUser;
}
