#include "sprintcreator.h"

SprintCreator::SprintCreator()
{
}

vector<Sprint*> SprintCreator::Create(Project* project)
{
    vector<Sprint*> sprints;

    // First sprint
    Sprint* sprint1 = new Sprint();
    sprint1->setName("Eerste iteratie");

    sprint1->setBeginDay(5);
    sprint1->setBeginMonth(12);
    sprint1->setBeginYear(2013);

    sprint1->setEndDay(4);
    sprint1->setEndMonth(3);
    sprint1->setEndYear(2014);

    project->addSprint(*sprint1);
    sprints.push_back(sprint1);

    // Second sprint
    Sprint* sprint2 = new Sprint();
    sprint2->setName("Tweede iteratie");

    sprint2->setBeginDay(5);
    sprint2->setBeginMonth(3);
    sprint2->setBeginYear(2014);

    sprint2->setEndDay(4);
    sprint2->setEndMonth(6);
    sprint2->setEndYear(2014);

    project->addSprint(*sprint2);
    sprints.push_back(sprint2);

    // Third sprint
    Sprint* sprint3 = new Sprint();
    sprint3->setName("Derde Iteratie");

    sprint3->setBeginDay(5);
    sprint3->setBeginMonth(6);
    sprint3->setBeginYear(2014);

    sprint3->setEndDay(4);
    sprint3->setEndMonth(9);
    sprint3->setEndYear(2014);

    project->addSprint(*sprint3);
    sprints.push_back(sprint3);

    // Fourth sprint
    Sprint* sprint4 = new Sprint();
    sprint4->setName("Vierde iteratie");

    sprint4->setBeginDay(5);
    sprint4->setBeginMonth(9);
    sprint4->setBeginYear(2014);

    sprint4->setEndDay(4);
    sprint4->setEndMonth(12);
    sprint4->setEndYear(2014);

    project->addSprint(*sprint4);
    sprints.push_back(sprint4);

    return sprints;
}
