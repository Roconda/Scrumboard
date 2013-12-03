#include <iostream>

#include "tfswrapper.h"
#include "TFS/TFSTransaction.h"
#include "TFS/Project.h"
#include "TFS/Sprint.h"

using std::cout;

TFSWrapper::TFSWrapper()
{
    // FIXME zorg voor project kies functionaliteit.
    this->selectedProject = TFSTransaction::remoteReadProject("the_orginal_kitten_mittens");
}

Project *TFSWrapper::getSelectedProject()
{
    return this->selectedProject;
}

void TFSWrapper::SaveSelectedProject()
{
    // TODO sla project op, als je geen verbinding hebt local, en als je verbinding hebt remote
}
