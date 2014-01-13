#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

#include "tfswrapper.h"
#include "TFS/TFSTransaction.h"
#include "TFS/Project.h"
#include "TFS/Sprint.h"
#include "TFS/StatusType.h"
#include "TFS/ProductBacklogItem.h"
#include "TFS/User.h"

#include "TestData/TestData.h"
#include "Visitors/pbivisitor.h"

using std::cout;

const char* TFSWrapper::SELECTED_PROJECT = "Scrumbag";

TFSWrapper::TFSWrapper(QObject *parent) : QObject(parent), selectedSprint(0), selectedPBI(0)
{
    // Reload testdata on startup
    //
    // TestData t;

    this->selectedProject = TFSTransaction::remoteReadProject(SELECTED_PROJECT);
    this->selectedUser = this->getSelectedUser();
}

Project *TFSWrapper::getSelectedProject()
{
    return this->selectedProject;
}

void TFSWrapper::saveSelectedProject()
{
    TFSTransaction::remoteWriteProject(SELECTED_PROJECT);
}

Sprint *TFSWrapper::setSelectedSprint(int index)
{
    emit TFSWrapper::instance().remoteTFSDataChanged();

    this->selectedSprint = index;
    this->selectedPBI = 0;
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

User *TFSWrapper::setSelectedUser(int index)
{
    User::ItemStorage::iterator uIter;

    for (uIter = User::getStorage().begin(); uIter != User::getStorage().end(); ++uIter) {
        if (std::distance(User::getStorage().begin(), uIter) == index)
            return this->selectedUser = uIter->second;
    }

    return nullptr;
}

size_t TFSWrapper::getSelectedUserIndex()
{
    if (this->selectedUser == nullptr)
        return -1;

    User::ItemStorage::iterator uIter;

    for (uIter = User::getStorage().begin(); uIter != User::getStorage().end(); ++uIter)
        if (uIter->second == this->selectedUser)
            return std::distance(User::getStorage().begin(), uIter);

    return -1;
}

ProductBacklogItem *TFSWrapper::setSelectedPBI(int pbi)
{
    this->selectedPBI = pbi;
    emit remoteTFSDataChanged();
    return getSelectedPBI();
}

ProductBacklogItem *TFSWrapper::getSelectedPBI()
{
    PBIVisitor pbivis;

    auto wia = TFSWrapper::instance().getSelectedSprint()->getWorkItemArray();
    for (auto &pbi : wia)
        if (pbi)
            pbi->accept(pbivis);

    if ((!pbivis.getList().empty()) && (this->selectedPBI < pbivis.getList().size()) )
        return pbivis.getList().at(this->selectedPBI);
    else
        return nullptr;
}

size_t TFSWrapper::getSelectedPBIIndex()
{
    return this->selectedPBI;
}
