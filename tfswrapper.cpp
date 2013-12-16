#include <iostream>

#include "tfswrapper.h"
#include "TFS/TFSTransaction.h"
#include "TFS/Project.h"
#include "TFS/Sprint.h"
#include "TFS/StatusType.h"


#include "createtestdata.h"

using std::cout;

TFSWrapper::TFSWrapper() : selectedSprint(0)
{
    //CreateTestData t;
    testobject = new TFSSignalObject();

    // FIXME zorg voor project kies functionaliteit.
    this->selectedProject = TFSTransaction::remoteReadProject("Sinterklaas Package Distribution Software");
}

Project *TFSWrapper::getSelectedProject()
{
    emit testobject->remoteTFSDataChanged();
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
