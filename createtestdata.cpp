#include "createtestdata.h"
#include "TFS/TFSTransaction.h"
#include "TFS/Project.h"
#include "TFS/Sprint.h"
#include "TFS/ProductBacklogItem.h"
#include "TFS/SprintBacklogItem.h"
#include "TFS/User.h"
#include "TFS/StatusType.h"
#include "TFS/Status.h"

#include <iostream>

using std::cout;

CreateTestData::CreateTestData()
{
    try
    {
        // ------------------------------ //
        // --------- CLIENT --------- //
        // ------------------------------ //

        // Delete all data from server.
        TFSTransaction::removeAllData();

        // Create a new empty local project.
        TFSTransaction::localWriteProject("Sinterklaas Package Distribution Software");

        // Link the new project to an instance.
        Project* project = Project::withName("Sinterklaas Package Distribution Software");

        // ----------- STATUSTYPE ----------- //

        StatusType *statusType1 = StatusType::withName("Not Started");
        StatusType *statusType2 = StatusType::withName("Started");
        StatusType *statusType3 = StatusType::withName("To Verify");
        StatusType *statusType4 = StatusType::withName("Done");

        statusType1->addNextStatusType(*statusType2);
        statusType2->addNextStatusType(*statusType3);
        statusType3->addNextStatusType(*statusType4);

        // ----------- PROJECT ----------- //

        // Startdate of project
        project->setBeginDay(5);
        project->setBeginMonth(12);
        project->setEndYear(2013);

        // Deadline of project
        project->setBeginDay(5);
        project->setBeginMonth(12);
        project->setEndYear(2014);

        // ----------- SPRINTS ----------- //

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

        // ----------- Users ----------- //

        User* user1 = User::withName("Projectpiet");
        User* user2 = User::withName("Ontwerppiet");
        User* user3 = User::withName("Bouwpiet");
        User* user4 = User::withName("TestPiet");
        User* user5 = User::withName("Typepiet");

        // ----------- TASKS ----------- //

        // --- Eerste iteratie --- //

        ProductBacklogItem *pbi1 = new ProductBacklogItem();
        pbi1->setTitle("PBI1");
        pbi1->setPriority(90);

        // Task 1
        SprintBacklogItem* task1 = new SprintBacklogItem();
        task1->setTitle("Plan van Aanpak");
        task1->setWorkItemNumber(1);
        task1->setDescription("Het plan van aanpak van Project SPDS");
        task1->setUser(user1);
        task1->setRemainingWork(60.0);

        Status *status1 = new Status();
        status1->setStatusType(*statusType1);
        task1->addStatus(*status1);

        // Task 2
        SprintBacklogItem* task2 = new SprintBacklogItem();
        task2->setTitle("Architectuurplan - Class Diagram");
        task2->setWorkItemNumber(2);
        task2->setDescription("Versie 0.1");
        task2->setRemainingWork(70.0);

        Status *status2 = new Status();
        status2->setStatusType(*statusType2);
        task2->addStatus(*status2);

        // Task 3
        SprintBacklogItem* task3 = new SprintBacklogItem();
        task3->setTitle("Class Pakje");
        task3->setWorkItemNumber(3);
        task3->setDescription("Kan je direct de header doorgeven? -Ontwerpiet");
        task3->setUser(user3);
        task3->setRemainingWork(20.0);

        Status *status3 = new Status();
        status3->setStatusType(*statusType3);
        task3->addStatus(*status3);

        // Task 4
        SprintBacklogItem* task4 = new SprintBacklogItem();
        task4->setTitle("Unit Tests: Class Pakje");
        task4->setWorkItemNumber(4);
        task4->setDescription("Vergeet niet method boolean Open()!");
        task4->setUser(user4);
        task4->setRemainingWork(30.0);

        Status *status4 = new Status();
        status4->setStatusType(*statusType4);
        task4->addStatus(*status4);

        // Task 5
        SprintBacklogItem* task5 = new SprintBacklogItem();
        task5->setTitle("Notule: Vergadering 05-12-2014");
        task5->setWorkItemNumber(5);
        task5->setDescription("");
        task5->setUser(user5);
        task5->setRemainingWork(30.0);

        task5->addStatus(*status4);

        // --- Tweede iteratie --- //

        // Task 6
        SprintBacklogItem* task6 = new SprintBacklogItem();
        task6->setTitle("SBI");
        task6->setWorkItemNumber(6);
        task6->setDescription("Vergadering over feedback van Hoofdpiet");
        task6->setUser(user1);
        task6->setRemainingWork(100.0);

        task6->addStatus(*status4);

        // --- Derde iteratie --- //
            // ...

        // --- Vierde iteratie --- //
            // ...


        // voeg tasks toe aan de PBI
        pbi1->addBacklogItem(*task1);
        pbi1->addBacklogItem(*task2);
        pbi1->addBacklogItem(*task3);
        pbi1->addBacklogItem(*task4);
        pbi1->addBacklogItem(*task5);
        pbi1->addBacklogItem(*task6);
        // voeg sbi toe aan sprint
        sprint1->addWorkItem(*task1);
        sprint1->addWorkItem(*task2);
        sprint1->addWorkItem(*task3);
        sprint1->addWorkItem(*task4);
        sprint1->addWorkItem(*task5);
        sprint1->addWorkItem(*task6);
        // voeg pbi toe aan sprint
        sprint1->addWorkItem(*pbi1);


        // ------------------------------ //
        // -------- SERVER -------- //
        // ------------------------------ //

        // Send the contents of the project from the client to the server.
        TFSTransaction::remoteWriteProject("Sinterklaas Package Distribution Software");

        // ----------- TESTING ----------- //
        Project* test = TFSTransaction::remoteReadProject("Sinterklaas Package Distribution Software");

        if(test->getSprint(0)->getWorkItem(0)->exists) {
            std::cout << "All done.";
        }
    }
    catch ( ... )
    {
        std::cout << "Installation script has failed";
    }
}
