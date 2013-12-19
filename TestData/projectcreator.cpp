#include "projectcreator.h"

ProjectCreator::ProjectCreator()
{
}

Project* ProjectCreator::Create()
{
    // Create a new empty local project.
    TFSTransaction::localWriteProject("Scrumbag");

    // Link the new project to an instance.
    Project* project = Project::withName("Scrumbag");

    // Startdate of project
    project->setBeginDay(5);
    project->setBeginMonth(12);
    project->setEndYear(2013);

    // Deadline of project
    project->setBeginDay(5);
    project->setBeginMonth(12);
    project->setEndYear(2014);

    return project;
}
