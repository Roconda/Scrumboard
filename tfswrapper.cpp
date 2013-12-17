#include <iostream>
#include <vector>

#include "tfswrapper.h"
#include "TFS/TFSTransaction.h"
#include "TFS/Project.h"
#include "TFS/Sprint.h"
#include "TFS/StatusType.h"
#include "TFS/SprintBacklogItem.h"
#include "TFS/User.h"


#include "createtestdata.h"

using std::cout;

TFSWrapper::TFSWrapper(QObject *parent) : QObject(parent), selectedSprint(0)
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
    // test
    emit TFSWrapper::instance().remoteTFSDataChanged();

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

/**
 * @brief Retrieves all available users
 * @return vector with available users
 */
std::vector<User*> TFSWrapper::getAllUsers() {
    std::vector<User*> users;

    User::ItemStorage::iterator iType;
    for(iType = User::getStorage().begin(); iType != User::getStorage().end(); ++iType){
        std::pair<std::string, User*> pair = *iType;
        users.push_back(pair.second);
    }

    return users;
}

/**
 * @brief Retrieves the currently selected user
 * @return User object
 */
User *TFSWrapper::getSelectedUser()
{
    // check if nullpointer, otherwise set the first User as default
    if(selectedUser == nullptr) {
        selectedUser = this->getAllUsers().back();
    }

    return selectedUser;
}

void TFSWrapper::setSelectedSBI(SprintBacklogItem *backlogitem)
{
    this->selectedSBI = backlogitem;
}

SprintBacklogItem *TFSWrapper::getSelectedSBI()
{
    return this->selectedSBI;
}
