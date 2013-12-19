#include "sbicreator.h"

SBICreator::SBICreator()
{
}


vector<SprintBacklogItem*> SBICreator::Create(vector<User*> users, vector<StatusType*> statusTypes, vector<ProductBacklogItem*> pbis, vector<Sprint*> sprints)
{
    vector<SprintBacklogItem*> sbis;

    //===============Product backlog item 1=================================
    SprintBacklogItem* task1 = new SprintBacklogItem();
    task1->setTitle("AKD versie 1");
    task1->setWorkItemNumber(1);
    task1->setDescription("AKD versie 1 maken.");
    task1->setUser(users[0]);
    task1->setRemainingWork(60.0);

    Status *status1 = new Status();
    status1->setStatusType(*statusTypes[0]);
    task1->addStatus(*status1);

    pbis[0]->addBacklogItem(*task1);
    sprints[0]->addWorkItem(*task1);


    SprintBacklogItem* task2 = new SprintBacklogItem();
    task2->setTitle("AKD controlleren");
    task2->setWorkItemNumber(2);
    task2->setDescription("Het gemaakte Applicatie Klasse diagram controlleren.");
    task2->setUser(users[1]);
    task2->setRemainingWork(60.0);

    Status *status2 = new Status();
    status2->setStatusType(*statusTypes[0]);
    task2->addStatus(*status2);

    pbis[0]->addBacklogItem(*task2);
    sprints[0]->addWorkItem(*task2);


    SprintBacklogItem* task3 = new SprintBacklogItem();
    task3->setTitle("AKD verbeteren");
    task3->setWorkItemNumber(3);
    task3->setDescription("De verbeterpunten doorvoeren om zo het AKD te verbeteren.");
    task3->setUser(users[2]);
    task3->setRemainingWork(60.0);

    Status *status3 = new Status();
    status3->setStatusType(*statusTypes[0]);
    task3->addStatus(*status3);

    pbis[0]->addBacklogItem(*task3);
    sprints[0]->addWorkItem(*task3);


    SprintBacklogItem* task4 = new SprintBacklogItem();
    task4->setTitle("AKD bespreken");
    task4->setWorkItemNumber(4);
    task4->setDescription("Het AKD met de groep bespreken om zo achter verbeterpunten te komen.");
    task4->setUser(users[3]);
    task4->setRemainingWork(60.0);

    Status *status4 = new Status();
    status4->setStatusType(*statusTypes[0]);
    task4->addStatus(*status4);

    pbis[0]->addBacklogItem(*task4);
    sprints[0]->addWorkItem(*task4);

    //===============Product backlog item 2=================================
    SprintBacklogItem* task5 = new SprintBacklogItem();
    task5->setTitle("Contact gegevens uitwisselen");
    task5->setWorkItemNumber(5);
    task5->setDescription("Contact gegevens van de groepsleden uitwisselen.");
    task5->setUser(users[4]);
    task5->setRemainingWork(60.0);

    Status *status5 = new Status();
    status5->setStatusType(*statusTypes[0]);
    task5->addStatus(*status5);

    pbis[1]->addBacklogItem(*task5);
    sprints[0]->addWorkItem(*task5);


    SprintBacklogItem* task6 = new SprintBacklogItem();
    task6->setTitle("Skype toevoegen");
    task6->setWorkItemNumber(6);
    task6->setDescription("Elkaar op skype toevoegen en een skype groep aanmaken.");
    task6->setUser(users[4]);
    task6->setRemainingWork(60.0);

    Status *status6 = new Status();
    status6->setStatusType(*statusTypes[0]);
    task6->addStatus(*status6);

    pbis[1]->addBacklogItem(*task6);
    sprints[0]->addWorkItem(*task6);


    SprintBacklogItem* task7 = new SprintBacklogItem();
    task7->setTitle("Trello aanmaken");
    task7->setWorkItemNumber(7);
    task7->setDescription("Een trello groep aanmaken, iedereen toevoegen en een bord openen.");
    task7->setUser(users[4]);
    task7->setRemainingWork(60.0);

    Status *status7 = new Status();
    status7->setStatusType(*statusTypes[0]);
    task7->addStatus(*status7);

    pbis[1]->addBacklogItem(*task7);
    sprints[0]->addWorkItem(*task7);


    SprintBacklogItem* task8 = new SprintBacklogItem();
    task8->setTitle("Git repository aanmaken");
    task8->setWorkItemNumber(8);
    task8->setDescription("Een git repository aanmaken, iedereen toevoegen en een initieel project starten.");
    task8->setUser(users[4]);
    task8->setRemainingWork(60.0);

    Status *status8 = new Status();
    status8->setStatusType(*statusTypes[0]);
    task8->addStatus(*status8);

    pbis[1]->addBacklogItem(*task8);
    sprints[0]->addWorkItem(*task8);

    //===============Product backlog item 3=================================
    SprintBacklogItem* task9 = new SprintBacklogItem();
    task9->setTitle("Ontwikkelomgeving bepalen");
    task9->setWorkItemNumber(9);
    task9->setDescription("Onderzoek doen naar mogelijke ontwikkelomgevingen en er een kiezen.");
    task9->setUser(users[4]);
    task9->setRemainingWork(60.0);

    Status *status9 = new Status();
    status9->setStatusType(*statusTypes[0]);
    task9->addStatus(*status9);

    pbis[2]->addBacklogItem(*task9);
    sprints[0]->addWorkItem(*task9);


    SprintBacklogItem* task10 = new SprintBacklogItem();
    task10->setTitle("Uitzoeken installatie ontwikkeltools");
    task10->setWorkItemNumber(10);
    task10->setDescription("Onderzoek doen naar hoe je de gekozen ontwikkeltool kan installeren en configureren.");
    task10->setUser(users[4]);
    task10->setRemainingWork(60.0);

    Status *status10 = new Status();
    status10->setStatusType(*statusTypes[0]);
    task10->addStatus(*status10);

    pbis[2]->addBacklogItem(*task10);
    sprints[0]->addWorkItem(*task10);


    SprintBacklogItem* task11 = new SprintBacklogItem();
    task11->setTitle("Ontwikkeltool installeren");
    task11->setWorkItemNumber(11);
    task11->setDescription("Overige leden ontwikkeltool installeren.");
    task11->setUser(users[4]);
    task11->setRemainingWork(60.0);

    Status *status11 = new Status();
    status11->setStatusType(*statusTypes[0]);
    task11->addStatus(*status11);

    pbis[2]->addBacklogItem(*task11);
    sprints[0]->addWorkItem(*task11);

    //===============Product backlog item 4=================================
    SprintBacklogItem* task12 = new SprintBacklogItem();
    task12->setTitle("Eerste opzet project");
    task12->setWorkItemNumber(12);
    task12->setDescription("Een eerste opzet maken van het project.");
    task12->setUser(users[4]);
    task12->setRemainingWork(60.0);

    Status *status12 = new Status();
    status12->setStatusType(*statusTypes[0]);
    task12->addStatus(*status12);

    pbis[3]->addBacklogItem(*task12);
    sprints[0]->addWorkItem(*task12);


    SprintBacklogItem* task13 = new SprintBacklogItem();
    task13->setTitle("Uitzoeken model van Bert");
    task13->setWorkItemNumber(13);
    task13->setDescription("Onderzoek doen naar het model geleverd door Bert Hoeks.");
    task13->setUser(users[4]);
    task13->setRemainingWork(60.0);

    Status *status13 = new Status();
    status13->setStatusType(*statusTypes[0]);
    task12->addStatus(*status13);

    pbis[3]->addBacklogItem(*task13);
    sprints[0]->addWorkItem(*task13);


    SprintBacklogItem* task14 = new SprintBacklogItem();
    task14->setTitle("Uitzoeken TFS");
    task14->setWorkItemNumber(14);
    task14->setDescription("Uitzoeken hoe we een eigen TFS server kunnen hosten.");
    task14->setUser(users[4]);
    task14->setRemainingWork(60.0);

    Status *status14 = new Status();
    status14->setStatusType(*statusTypes[0]);
    task14->addStatus(*status14);

    pbis[3]->addBacklogItem(*task14);
    sprints[0]->addWorkItem(*task14);


    SprintBacklogItem* task15 = new SprintBacklogItem();
    task15->setTitle("Datamodel bekijken");
    task15->setWorkItemNumber(15);
    task15->setDescription("Onderzoeken relaties binnen het TFS model.");
    task15->setUser(users[4]);
    task15->setRemainingWork(60.0);

    Status *status15 = new Status();
    status15->setStatusType(*statusTypes[0]);
    task15->addStatus(*status15);

    pbis[3]->addBacklogItem(*task15);
    sprints[0]->addWorkItem(*task15);

    //===============Product backlog item 5=================================
    SprintBacklogItem* task16 = new SprintBacklogItem();
    task16->setTitle("Architectuur document");
    task16->setWorkItemNumber(16);
    task16->setDescription("Begin maken aan het architectuur document met gemaakte keuzes en beargumentatie.");
    task16->setUser(users[4]);
    task16->setRemainingWork(60.0);

    Status *status16 = new Status();
    status16->setStatusType(*statusTypes[0]);
    task16->addStatus(*status16);

    pbis[4]->addBacklogItem(*task16);
    sprints[0]->addWorkItem(*task16);


    SprintBacklogItem* task17 = new SprintBacklogItem();
    task17->setTitle("Architectuur keuzes");
    task17->setWorkItemNumber(17);
    task17->setDescription("Bepalen welke keuzes er gemaakt zijn.");
    task17->setUser(users[4]);
    task17->setRemainingWork(60.0);

    Status *status17 = new Status();
    status17->setStatusType(*statusTypes[0]);
    task17->addStatus(*status17);

    pbis[4]->addBacklogItem(*task17);
    sprints[0]->addWorkItem(*task17);


    SprintBacklogItem* task18 = new SprintBacklogItem();
    task18->setTitle("Sequence diagrammen");
    task18->setWorkItemNumber(18);
    task18->setDescription("Bepalen welke Sequence Diagrammen er gemaakt moeten worden.");
    task18->setUser(users[4]);
    task18->setRemainingWork(60.0);

    Status *status18 = new Status();
    status18->setStatusType(*statusTypes[0]);
    task18->addStatus(*status18);

    pbis[4]->addBacklogItem(*task18);
    sprints[0]->addWorkItem(*task18);

    //===============Product backlog item 6=================================
    SprintBacklogItem* task19 = new SprintBacklogItem();
    task19->setTitle("Wat te testen");
    task19->setWorkItemNumber(19);
    task19->setDescription("Bepalen wat er getest gaat worden.");
    task19->setUser(users[4]);
    task19->setRemainingWork(60.0);

    Status *status19 = new Status();
    status19->setStatusType(*statusTypes[0]);
    task19->addStatus(*status19);

    pbis[5]->addBacklogItem(*task19);
    sprints[0]->addWorkItem(*task19);


    SprintBacklogItem* task20 = new SprintBacklogItem();
    task20->setTitle("Testcases vaststellen");
    task20->setWorkItemNumber(20);
    task20->setDescription("Het vastleggen van de testcases.");
    task20->setUser(users[4]);
    task20->setRemainingWork(60.0);

    Status *status20 = new Status();
    status20->setStatusType(*statusTypes[0]);
    task20->addStatus(*status20);

    pbis[5]->addBacklogItem(*task20);
    sprints[0]->addWorkItem(*task20);


    SprintBacklogItem* task21 = new SprintBacklogItem();
    task21->setTitle("Testcase 1 uitvoeren");
    task21->setWorkItemNumber(21);
    task21->setDescription("Het uitvoeren van de eerste testcase.");
    task21->setUser(users[4]);
    task21->setRemainingWork(60.0);

    Status *status21 = new Status();
    status21->setStatusType(*statusTypes[0]);
    task21->addStatus(*status21);

    pbis[5]->addBacklogItem(*task21);
    sprints[0]->addWorkItem(*task21);

    //===============Product backlog item 7=================================
    SprintBacklogItem* task22 = new SprintBacklogItem();
    task22->setTitle("Overleg inhoud presentatie");
    task22->setWorkItemNumber(22);
    task22->setDescription("Overleggen over de inhoud van de presentatie.");
    task22->setUser(users[4]);
    task22->setRemainingWork(60.0);

    Status *status22 = new Status();
    status22->setStatusType(*statusTypes[0]);
    task22->addStatus(*status22);

    pbis[6]->addBacklogItem(*task22);
    sprints[0]->addWorkItem(*task22);


    SprintBacklogItem* task23 = new SprintBacklogItem();
    task23->setTitle("Presentatie voorbereiden");
    task23->setWorkItemNumber(19);
    task23->setDescription("Presentatie sheets maken en eventueel andere voorbereidingen.");
    task23->setUser(users[4]);
    task23->setRemainingWork(60.0);

    Status *status23 = new Status();
    status23->setStatusType(*statusTypes[0]);
    task23->addStatus(*status23);

    pbis[6]->addBacklogItem(*task23);
    sprints[0]->addWorkItem(*task23);


    SprintBacklogItem* task24 = new SprintBacklogItem();
    task24->setTitle("Presentatie geven");
    task24->setWorkItemNumber(19);
    task24->setDescription("Presentatie geven aan de klant.");
    task24->setUser(users[4]);
    task24->setRemainingWork(60.0);

    Status *status24 = new Status();
    status24->setStatusType(*statusTypes[0]);
    task24->addStatus(*status24);

    pbis[6]->addBacklogItem(*task24);
    sprints[0]->addWorkItem(*task24);

    return sbis;
}
