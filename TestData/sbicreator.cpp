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
    task1->setRemainingWork(10);
    task1->setCompletedWork(0);
    task1->setBaselineWork(10);

    Status *status1 = new Status();
    status1->setStatusType(*statusTypes[0]);
    task1->addStatus(*status1);

    pbis[0]->addBacklogItem(*task1);
    sprints[0]->addWorkItem(*task1);
    sbis.push_back(task1);


    SprintBacklogItem* task2 = new SprintBacklogItem();
    task2->setTitle("AKD controlleren");
    task2->setWorkItemNumber(2);
    task2->setDescription("Het gemaakte Applicatie Klasse diagram controlleren.");
    task2->setUser(users[1]);
    task2->setRemainingWork(5);
    task2->setCompletedWork(0);
    task2->setBaselineWork(5);

    Status *status2 = new Status();
    status2->setStatusType(*statusTypes[0]);
    task2->addStatus(*status2);

    pbis[0]->addBacklogItem(*task2);
    sprints[0]->addWorkItem(*task2);
    sbis.push_back(task2);


    SprintBacklogItem* task3 = new SprintBacklogItem();
    task3->setTitle("AKD verbeteren");
    task3->setWorkItemNumber(3);
    task3->setDescription("De verbeterpunten doorvoeren om zo het AKD te verbeteren.");
    task3->setUser(users[2]);
    task3->setRemainingWork(5);
    task3->setCompletedWork(0);
    task3->setBaselineWork(5);

    Status *status3 = new Status();
    status3->setStatusType(*statusTypes[0]);
    task3->addStatus(*status3);

    pbis[0]->addBacklogItem(*task3);
    sprints[0]->addWorkItem(*task3);
    sbis.push_back(task3);


    SprintBacklogItem* task4 = new SprintBacklogItem();
    task4->setTitle("AKD bespreken");
    task4->setWorkItemNumber(4);
    task4->setDescription("Het AKD met de groep bespreken om zo achter verbeterpunten te komen.");
    task4->setUser(users[3]);
    task4->setRemainingWork(1);
    task4->setCompletedWork(0);
    task4->setBaselineWork(1);

    Status *status4 = new Status();
    status4->setStatusType(*statusTypes[0]);
    task4->addStatus(*status4);

    pbis[0]->addBacklogItem(*task4);
    sprints[0]->addWorkItem(*task4);
    sbis.push_back(task4);

    //===============Product backlog item 2=================================
    SprintBacklogItem* task5 = new SprintBacklogItem();
    task5->setTitle("Contact gegevens uitwisselen");
    task5->setWorkItemNumber(5);
    task5->setDescription("Contact gegevens van de groepsleden uitwisselen.");
    task5->setUser(users[4]);
    task5->setRemainingWork(1);
    task5->setCompletedWork(0);
    task5->setBaselineWork(1);

    Status *status5 = new Status();
    status5->setStatusType(*statusTypes[0]);
    task5->addStatus(*status5);

    pbis[1]->addBacklogItem(*task5);
    sprints[0]->addWorkItem(*task5);
    sbis.push_back(task5);


    SprintBacklogItem* task6 = new SprintBacklogItem();
    task6->setTitle("Skype toevoegen");
    task6->setWorkItemNumber(6);
    task6->setDescription("Elkaar op skype toevoegen en een skype groep aanmaken.");
    task6->setUser(users[5]);
    task6->setRemainingWork(1);
    task6->setCompletedWork(0);
    task6->setBaselineWork(1);

    Status *status6 = new Status();
    status6->setStatusType(*statusTypes[0]);
    task6->addStatus(*status6);

    pbis[1]->addBacklogItem(*task6);
    sprints[0]->addWorkItem(*task6);
    sbis.push_back(task6);


    SprintBacklogItem* task7 = new SprintBacklogItem();
    task7->setTitle("Trello aanmaken");
    task7->setWorkItemNumber(7);
    task7->setDescription("Een trello groep aanmaken, iedereen toevoegen en een bord openen.");
    task7->setUser(users[0]);
    task7->setRemainingWork(1);
    task7->setCompletedWork(0);
    task7->setBaselineWork(1);

    Status *status7 = new Status();
    status7->setStatusType(*statusTypes[0]);
    task7->addStatus(*status7);

    pbis[1]->addBacklogItem(*task7);
    sprints[0]->addWorkItem(*task7);
    sbis.push_back(task7);


    SprintBacklogItem* task8 = new SprintBacklogItem();
    task8->setTitle("Git repository aanmaken");
    task8->setWorkItemNumber(8);
    task8->setDescription("Een git repository aanmaken, iedereen toevoegen en een initieel project starten.");
    task8->setUser(users[1]);
    task8->setRemainingWork(1);
    task8->setCompletedWork(0);
    task8->setBaselineWork(1);

    Status *status8 = new Status();
    status8->setStatusType(*statusTypes[0]);
    task8->addStatus(*status8);

    pbis[1]->addBacklogItem(*task8);
    sprints[0]->addWorkItem(*task8);
    sbis.push_back(task8);

    //===============Product backlog item 3=================================
    SprintBacklogItem* task9 = new SprintBacklogItem();
    task9->setTitle("Ontwikkelomgeving bepalen");
    task9->setWorkItemNumber(9);
    task9->setDescription("Onderzoek doen naar mogelijke ontwikkelomgevingen en er een kiezen.");
    task9->setUser(users[2]);
    task9->setRemainingWork(2);
    task9->setCompletedWork(0);
    task9->setBaselineWork(2);

    Status *status9 = new Status();
    status9->setStatusType(*statusTypes[0]);
    task9->addStatus(*status9);

    pbis[2]->addBacklogItem(*task9);
    sprints[0]->addWorkItem(*task9);
    sbis.push_back(task9);


    SprintBacklogItem* task10 = new SprintBacklogItem();
    task10->setTitle("Uitzoeken installatie ontwikkeltools");
    task10->setWorkItemNumber(10);
    task10->setDescription("Installatie van tool uitzoeken.");
    task10->setUser(users[3]);
    task10->setRemainingWork(5);
    task10->setCompletedWork(0);
    task10->setBaselineWork(5);

    Status *status10 = new Status();
    status10->setStatusType(*statusTypes[0]);
    task10->addStatus(*status10);

    pbis[2]->addBacklogItem(*task10);
    sprints[0]->addWorkItem(*task10);
    sbis.push_back(task10);


    SprintBacklogItem* task11 = new SprintBacklogItem();
    task11->setTitle("Ontwikkeltool installeren");
    task11->setWorkItemNumber(11);
    task11->setDescription("Overige leden ontwikkeltool installeren.");
    task11->setUser(users[4]);
    task11->setRemainingWork(5);
    task11->setCompletedWork(0);
    task11->setBaselineWork(5);

    Status *status11 = new Status();
    status11->setStatusType(*statusTypes[0]);
    task11->addStatus(*status11);

    pbis[2]->addBacklogItem(*task11);
    sprints[0]->addWorkItem(*task11);
    sbis.push_back(task11);

    //===============Product backlog item 4=================================
    SprintBacklogItem* task12 = new SprintBacklogItem();
    task12->setTitle("Eerste opzet project");
    task12->setWorkItemNumber(12);
    task12->setDescription("Een eerste opzet maken van het project.");
    task12->setUser(users[5]);
    task12->setRemainingWork(4);
    task12->setCompletedWork(0);
    task12->setBaselineWork(4);

    Status *status12 = new Status();
    status12->setStatusType(*statusTypes[0]);
    task12->addStatus(*status12);

    pbis[3]->addBacklogItem(*task12);
    sprints[0]->addWorkItem(*task12);
    sbis.push_back(task12);


    SprintBacklogItem* task13 = new SprintBacklogItem();
    task13->setTitle("Uitzoeken model van Bert");
    task13->setWorkItemNumber(13);
    task13->setDescription("Onderzoek doen naar het model geleverd door Bert Hoeks.");
    task13->setUser(users[0]);
    task13->setRemainingWork(5);
    task13->setCompletedWork(0);
    task13->setBaselineWork(5);

    Status *status13 = new Status();
    status13->setStatusType(*statusTypes[0]);
    task12->addStatus(*status13);

    pbis[3]->addBacklogItem(*task13);
    sprints[0]->addWorkItem(*task13);
    sbis.push_back(task13);


    SprintBacklogItem* task14 = new SprintBacklogItem();
    task14->setTitle("Uitzoeken TFS");
    task14->setWorkItemNumber(14);
    task14->setDescription("Uitzoeken hoe we een eigen TFS server kunnen hosten.");
    task14->setUser(users[1]);
    task14->setRemainingWork(10);
    task14->setCompletedWork(0);
    task14->setBaselineWork(10);

    Status *status14 = new Status();
    status14->setStatusType(*statusTypes[0]);
    task14->addStatus(*status14);

    pbis[3]->addBacklogItem(*task14);
    sprints[0]->addWorkItem(*task14);
    sbis.push_back(task14);


    SprintBacklogItem* task15 = new SprintBacklogItem();
    task15->setTitle("Datamodel bekijken");
    task15->setWorkItemNumber(15);
    task15->setDescription("Onderzoeken relaties binnen het TFS model.");
    task15->setUser(users[2]);
    task15->setRemainingWork(3);
    task15->setCompletedWork(0);
    task15->setBaselineWork(3);

    Status *status15 = new Status();
    status15->setStatusType(*statusTypes[0]);
    task15->addStatus(*status15);

    pbis[3]->addBacklogItem(*task15);
    sprints[0]->addWorkItem(*task15);
    sbis.push_back(task15);

    //===============Product backlog item 5=================================
    SprintBacklogItem* task16 = new SprintBacklogItem();
    task16->setTitle("Architectuur document");
    task16->setWorkItemNumber(16);
    task16->setDescription("Begin maken aan het architectuur document met gemaakte keuzes en beargumentatie.");
    task16->setUser(users[3]);
    task16->setRemainingWork(20);
    task16->setCompletedWork(0);
    task16->setBaselineWork(20);

    Status *status16 = new Status();
    status16->setStatusType(*statusTypes[0]);
    task16->addStatus(*status16);

    pbis[4]->addBacklogItem(*task16);
    sprints[0]->addWorkItem(*task16);
    sbis.push_back(task16);


    SprintBacklogItem* task17 = new SprintBacklogItem();
    task17->setTitle("Architectuur keuzes");
    task17->setWorkItemNumber(17);
    task17->setDescription("Bepalen welke keuzes er gemaakt zijn.");
    task17->setUser(users[4]);
    task17->setRemainingWork(10);
    task17->setCompletedWork(0);
    task17->setBaselineWork(10);

    Status *status17 = new Status();
    status17->setStatusType(*statusTypes[0]);
    task17->addStatus(*status17);

    pbis[4]->addBacklogItem(*task17);
    sprints[0]->addWorkItem(*task17);
    sbis.push_back(task17);


    SprintBacklogItem* task18 = new SprintBacklogItem();
    task18->setTitle("Sequence diagrammen");
    task18->setWorkItemNumber(18);
    task18->setDescription("Bepalen welke Sequence Diagrammen er gemaakt moeten worden.");
    task18->setUser(users[5]);
    task18->setRemainingWork(5);
    task18->setCompletedWork(0);
    task18->setBaselineWork(5);

    Status *status18 = new Status();
    status18->setStatusType(*statusTypes[0]);
    task18->addStatus(*status18);

    pbis[4]->addBacklogItem(*task18);
    sprints[0]->addWorkItem(*task18);
    sbis.push_back(task18);

    //===============Product backlog item 6=================================
    SprintBacklogItem* task19 = new SprintBacklogItem();
    task19->setTitle("Wat te testen");
    task19->setWorkItemNumber(19);
    task19->setDescription("Bepalen wat er getest gaat worden.");
    task19->setUser(users[0]);
    task19->setRemainingWork(10);
    task19->setCompletedWork(0);
    task19->setBaselineWork(10);

    Status *status19 = new Status();
    status19->setStatusType(*statusTypes[0]);
    task19->addStatus(*status19);

    pbis[5]->addBacklogItem(*task19);
    sprints[0]->addWorkItem(*task19);
    sbis.push_back(task19);


    SprintBacklogItem* task20 = new SprintBacklogItem();
    task20->setTitle("Testcases vaststellen");
    task20->setWorkItemNumber(20);
    task20->setDescription("Het vastleggen van de testcases.");
    task20->setUser(users[1]);
    task20->setRemainingWork(10);
    task20->setCompletedWork(0);
    task20->setBaselineWork(10);

    Status *status20 = new Status();
    status20->setStatusType(*statusTypes[0]);
    task20->addStatus(*status20);

    pbis[5]->addBacklogItem(*task20);
    sprints[0]->addWorkItem(*task20);
    sbis.push_back(task20);


    SprintBacklogItem* task21 = new SprintBacklogItem();
    task21->setTitle("Testcase 1 uitvoeren");
    task21->setWorkItemNumber(21);
    task21->setDescription("Het uitvoeren van de eerste testcase.");
    task21->setUser(users[2]);
    task21->setRemainingWork(3);
    task21->setCompletedWork(0);
    task21->setBaselineWork(3);

    Status *status21 = new Status();
    status21->setStatusType(*statusTypes[0]);
    task21->addStatus(*status21);

    pbis[5]->addBacklogItem(*task21);
    sprints[0]->addWorkItem(*task21);
    sbis.push_back(task21);

    //===============Product backlog item 7=================================
    SprintBacklogItem* task22 = new SprintBacklogItem();
    task22->setTitle("Overleg inhoud presentatie");
    task22->setWorkItemNumber(22);
    task22->setDescription("Overleggen over de inhoud van de presentatie.");
    task22->setUser(users[3]);
    task22->setRemainingWork(5);
    task22->setCompletedWork(0);
    task22->setBaselineWork(5);

    Status *status22 = new Status();
    status22->setStatusType(*statusTypes[0]);
    task22->addStatus(*status22);

    pbis[6]->addBacklogItem(*task22);
    sprints[0]->addWorkItem(*task22);
    sbis.push_back(task22);


    SprintBacklogItem* task23 = new SprintBacklogItem();
    task23->setTitle("Presentatie voorbereiden");
    task23->setWorkItemNumber(23);
    task23->setDescription("Presentatie sheets maken en eventueel andere voorbereidingen.");
    task23->setUser(users[4]);
    task23->setRemainingWork(10);
    task23->setCompletedWork(0);
    task23->setBaselineWork(10);

    Status *status23 = new Status();
    status23->setStatusType(*statusTypes[0]);
    task23->addStatus(*status23);

    pbis[6]->addBacklogItem(*task23);
    sprints[0]->addWorkItem(*task23);
    sbis.push_back(task23);


    SprintBacklogItem* task24 = new SprintBacklogItem();
    task24->setTitle("Presentatie geven");
    task24->setWorkItemNumber(24);
    task24->setDescription("Presentatie geven aan de klant.");
    task24->setUser(users[5]);
    task24->setRemainingWork(15);
    task24->setCompletedWork(0);
    task24->setBaselineWork(15);

    Status *status24 = new Status();
    status24->setStatusType(*statusTypes[0]);
    task24->addStatus(*status24);

    pbis[6]->addBacklogItem(*task24);
    sprints[0]->addWorkItem(*task24);
    sbis.push_back(task24);

    //===============      Sprint 2        =================================
    //===============Product backlog item 8=================================
    SprintBacklogItem* task25 = new SprintBacklogItem();
    task25->setTitle("AKD versie 2");
    task25->setWorkItemNumber(25);
    task25->setDescription("AKD versie 2 maken");
    task25->setUser(users[5]);
    task25->setRemainingWork(8);
    task25->setCompletedWork(0);
    task25->setBaselineWork(8);

    Status *status25 = new Status();
    status25->setStatusType(*statusTypes[0]);
    task25->addStatus(*status25);

    pbis[7]->addBacklogItem(*task25);
    sprints[0]->addWorkItem(*task25);
    sbis.push_back(task25);

    SprintBacklogItem* task26 = new SprintBacklogItem();
    task26->setTitle("AKD controleren");
    task26->setWorkItemNumber(26);
    task26->setDescription("Het gemaakte AKD controleren");
    task26->setUser(users[5]);
    task26->setRemainingWork(4);
    task26->setCompletedWork(0);
    task26->setBaselineWork(4);

    Status *status26 = new Status();
    status26->setStatusType(*statusTypes[0]);
    task26->addStatus(*status26);

    pbis[7]->addBacklogItem(*task26);
    sprints[0]->addWorkItem(*task26);
    sbis.push_back(task26);

    SprintBacklogItem* task27 = new SprintBacklogItem();
    task27->setTitle("AKD verbeteren");
    task27->setWorkItemNumber(27);
    task27->setDescription("Het gemaakte AKD verbeteren");
    task27->setUser(users[5]);
    task27->setRemainingWork(4);
    task27->setCompletedWork(0);
    task27->setBaselineWork(4);

    Status *status27 = new Status();
    status27->setStatusType(*statusTypes[0]);
    task27->addStatus(*status27);

    pbis[7]->addBacklogItem(*task27);
    sprints[0]->addWorkItem(*task27);
    sbis.push_back(task27);

    SprintBacklogItem* task28 = new SprintBacklogItem();
    task28->setTitle("AKD bespreken");
    task28->setWorkItemNumber(28);
    task28->setDescription("Het gemaakte AKD bespreken met de groep");
    task28->setUser(users[5]);
    task28->setRemainingWork(1);
    task28->setCompletedWork(0);
    task28->setBaselineWork(1);

    Status *status28 = new Status();
    status28->setStatusType(*statusTypes[0]);
    task28->addStatus(*status28);

    pbis[7]->addBacklogItem(*task28);
    sprints[0]->addWorkItem(*task28);
    sbis.push_back(task28);

    //===============Product backlog item 9=================================
    SprintBacklogItem* task29 = new SprintBacklogItem();
    task29->setTitle("Tweede opzet project");
    task29->setWorkItemNumber(29);
    task29->setDescription("Tweede opzet maken van het project");
    task29->setUser(users[5]);
    task29->setRemainingWork(10);
    task29->setCompletedWork(0);
    task29->setBaselineWork(10);

    Status *status29 = new Status();
    status29->setStatusType(*statusTypes[0]);
    task29->addStatus(*status29);

    pbis[8]->addBacklogItem(*task29);
    sprints[0]->addWorkItem(*task29);
    sbis.push_back(task29);

    SprintBacklogItem* task30 = new SprintBacklogItem();
    task30->setTitle("Userstory 12 realiseren");
    task30->setWorkItemNumber(30);
    task30->setDescription("Userstory 12 realiseren");
    task30->setUser(users[5]);
    task30->setRemainingWork(8);
    task30->setCompletedWork(0);
    task30->setBaselineWork(8);

    Status *status30 = new Status();
    status30->setStatusType(*statusTypes[0]);
    task30->addStatus(*status30);

    pbis[8]->addBacklogItem(*task30);
    sprints[0]->addWorkItem(*task30);
    sbis.push_back(task30);

    SprintBacklogItem* task31 = new SprintBacklogItem();
    task31->setTitle("Userstory 7 realiseren");
    task31->setWorkItemNumber(31);
    task31->setDescription("Userstory 7 realiseren");
    task31->setUser(users[5]);
    task31->setRemainingWork(7);
    task31->setCompletedWork(0);
    task31->setBaselineWork(7);

    Status *status31 = new Status();
    status31->setStatusType(*statusTypes[0]);
    task31->addStatus(*status31);

    pbis[8]->addBacklogItem(*task31);
    sprints[0]->addWorkItem(*task31);
    sbis.push_back(task31);

    SprintBacklogItem* task32 = new SprintBacklogItem();
    task32->setTitle("Userstory 8 realiseren");
    task32->setWorkItemNumber(32);
    task32->setDescription("Userstory 8 realiseren");
    task32->setUser(users[5]);
    task32->setRemainingWork(14);
    task32->setCompletedWork(0);
    task32->setBaselineWork(14);

    Status *status32 = new Status();
    status32->setStatusType(*statusTypes[0]);
    task32->addStatus(*status32);

    pbis[8]->addBacklogItem(*task32);
    sprints[0]->addWorkItem(*task32);
    sbis.push_back(task32);

    SprintBacklogItem* task33 = new SprintBacklogItem();
    task33->setTitle("Userstory 15 realiseren");
    task33->setWorkItemNumber(33);
    task33->setDescription("Userstory 15 realiseren");
    task33->setUser(users[5]);
    task33->setRemainingWork(10);
    task33->setCompletedWork(0);
    task33->setBaselineWork(10);

    Status *status33 = new Status();
    status33->setStatusType(*statusTypes[0]);
    task33->addStatus(*status33);

    pbis[8]->addBacklogItem(*task33);
    sprints[0]->addWorkItem(*task33);
    sbis.push_back(task33);

    //===============Product backlog item 10=================================
    SprintBacklogItem* task34 = new SprintBacklogItem();
    task34->setTitle("Architectuur document bijwerken");
    task34->setWorkItemNumber(34);
    task34->setDescription("Architectuur document bijwerken met de nieuwe code");
    task34->setUser(users[5]);
    task34->setRemainingWork(8);
    task34->setCompletedWork(0);
    task34->setBaselineWork(8);

    Status *status34 = new Status();
    status34->setStatusType(*statusTypes[0]);
    task34->addStatus(*status34);

    pbis[9]->addBacklogItem(*task34);
    sprints[0]->addWorkItem(*task34);
    sbis.push_back(task34);

    SprintBacklogItem* task35 = new SprintBacklogItem();
    task35->setTitle("Architectuur document bijwerken");
    task35->setWorkItemNumber(35);
    task35->setDescription("Architectuur document bijwerken met de nieuwe code");
    task35->setUser(users[5]);
    task35->setRemainingWork(5);
    task35->setCompletedWork(0);
    task35->setBaselineWork(5);

    Status *status35 = new Status();
    status35->setStatusType(*statusTypes[0]);
    task35->addStatus(*status35);

    pbis[9]->addBacklogItem(*task35);
    sprints[0]->addWorkItem(*task35);
    sbis.push_back(task35);

    //===============Product backlog item 11=================================
    SprintBacklogItem* task36 = new SprintBacklogItem();
    task36->setTitle("Testcases bepalen");
    task36->setWorkItemNumber(36);
    task36->setDescription("Het bepalen van de testcases van deze sprint.");
    task36->setUser(users[5]);
    task36->setRemainingWork(8);
    task36->setCompletedWork(0);
    task36->setBaselineWork(8);

    Status *status36 = new Status();
    status36->setStatusType(*statusTypes[0]);
    task36->addStatus(*status36);

    pbis[10]->addBacklogItem(*task36);
    sprints[0]->addWorkItem(*task36);
    sbis.push_back(task36);

    SprintBacklogItem* task37 = new SprintBacklogItem();
    task37->setTitle("Testcases verdelen");
    task37->setWorkItemNumber(37);
    task37->setDescription("Het verdelen van de testcases die uitgevoerd worden.");
    task37->setUser(users[5]);
    task37->setRemainingWork(1);
    task37->setCompletedWork(0);
    task37->setBaselineWork(1);

    Status *status37 = new Status();
    status37->setStatusType(*statusTypes[0]);
    task37->addStatus(*status37);

    pbis[10]->addBacklogItem(*task37);
    sprints[0]->addWorkItem(*task37);
    sbis.push_back(task37);

    SprintBacklogItem* task38 = new SprintBacklogItem();
    task38->setTitle("Tweede testcases uitvoeren");
    task38->setWorkItemNumber(38);
    task38->setDescription("Het uitvoeren van de testcases van deze sprint.");
    task38->setUser(users[5]);
    task38->setRemainingWork(5);
    task38->setCompletedWork(0);
    task38->setBaselineWork(5);

    Status *status38 = new Status();
    status38->setStatusType(*statusTypes[0]);
    task38->addStatus(*status38);

    pbis[10]->addBacklogItem(*task38);
    sprints[0]->addWorkItem(*task38);
    sbis.push_back(task38);

    //===============Product backlog item 12=================================
    SprintBacklogItem* task39 = new SprintBacklogItem();
    task39->setTitle("Bepalen wie presentatie geeft");
    task39->setWorkItemNumber(39);
    task39->setDescription("Bepalen wie de presentatie van deze sprint geeft.");
    task39->setUser(users[5]);
    task39->setRemainingWork(2);
    task39->setCompletedWork(0);
    task39->setBaselineWork(2);

    Status *status39 = new Status();
    status39->setStatusType(*statusTypes[0]);
    task39->addStatus(*status39);

    pbis[11]->addBacklogItem(*task39);
    sprints[0]->addWorkItem(*task39);
    sbis.push_back(task39);

    SprintBacklogItem* task40 = new SprintBacklogItem();
    task40->setTitle("Presentatie sheets maken");
    task40->setWorkItemNumber(40);
    task40->setDescription("Het maken van de sheets voor de presentatie.");
    task40->setUser(users[5]);
    task40->setRemainingWork(10);
    task40->setCompletedWork(0);
    task40->setBaselineWork(10);

    Status *status40 = new Status();
    status40->setStatusType(*statusTypes[0]);
    task40->addStatus(*status40);

    pbis[11]->addBacklogItem(*task40);
    sprints[0]->addWorkItem(*task40);
    sbis.push_back(task40);

    SprintBacklogItem* task41 = new SprintBacklogItem();
    task41->setTitle("Presentatie geven");
    task41->setWorkItemNumber(41);
    task41->setDescription("Het geven van de presentatie aan de opdrachtgevers.");
    task41->setUser(users[5]);
    task41->setRemainingWork(1);
    task41->setCompletedWork(0);
    task41->setBaselineWork(10);

    Status *status41 = new Status();
    status41->setStatusType(*statusTypes[0]);
    task41->addStatus(*status4);

    pbis[11]->addBacklogItem(*task41);
    sprints[0]->addWorkItem(*task41);
    sbis.push_back(task41);

    //===============Product backlog item 13=================================
    SprintBacklogItem* task42 = new SprintBacklogItem();
    task42->setTitle("AKD versie 3");
    task42->setWorkItemNumber(42);
    task42->setDescription("AKD versie 3 maken.");
    task42->setUser(users[3]);
    task42->setRemainingWork(6);
    task42->setCompletedWork(0);
    task42->setBaselineWork(6);

    Status *status42 = new Status();
    status42->setStatusType(*statusTypes[2]);
    task42->addStatus(*status42);

    pbis[12]->addBacklogItem(*task42);
    sprints[2]->addWorkItem(*task42);
    sbis.push_back(task42);

    SprintBacklogItem* task43 = new SprintBacklogItem();
    task43->setTitle("AKD controleren");
    task43->setWorkItemNumber(43);
    task43->setDescription("Versie 3 van het AKD controleren.");
    task43->setUser(users[2]);
    task43->setRemainingWork(2);
    task43->setCompletedWork(0);
    task43->setBaselineWork(2);

    Status *status43 = new Status();
    status43->setStatusType(*statusTypes[2]);
    task43->addStatus(*status43);

    pbis[12]->addBacklogItem(*task43);
    sprints[2]->addWorkItem(*task43);
    sbis.push_back(task43);

    SprintBacklogItem* task44 = new SprintBacklogItem();
    task44->setTitle("AKD verbeteren");
    task44->setWorkItemNumber(44);
    task44->setDescription("AKD verbeteren aan de hand van feedback van controle.");
    task44->setUser(users[4]);
    task44->setRemainingWork(4);
    task44->setCompletedWork(0);
    task44->setBaselineWork(4);

    Status *status44 = new Status();
    status44->setStatusType(*statusTypes[1]);
    task44->addStatus(*status44);

    pbis[12]->addBacklogItem(*task44);
    sprints[2]->addWorkItem(*task44);
    sbis.push_back(task44);

    SprintBacklogItem* task45 = new SprintBacklogItem();
    task45->setTitle("AKD bespreken");
    task45->setWorkItemNumber(45);
    task45->setDescription("Verbeterde AKD doorbespreken.");
    task45->setUser(users[3]);
    task45->setRemainingWork(1);
    task45->setCompletedWork(0);
    task45->setBaselineWork(1);

    Status *status45 = new Status();
    status45->setStatusType(*statusTypes[1]);
    task45->addStatus(*status45);

    pbis[12]->addBacklogItem(*task45);
    sprints[2]->addWorkItem(*task45);
    sbis.push_back(task45);

    //===============Product backlog item 14=================================
    SprintBacklogItem* task46 = new SprintBacklogItem();
    task46->setTitle("Userstory 2 realiseren");
    task46->setWorkItemNumber(46);
    task46->setDescription("Als gebruiker wil ik alle SBI's op het bord kunnen zien van 1 sprint.");
    task46->setUser(users[1]);
    task46->setRemainingWork(4);
    task46->setCompletedWork(0);
    task46->setBaselineWork(4);

    Status *status46 = new Status();
    status46->setStatusType(*statusTypes[0]);
    task46->addStatus(*status46);

    pbis[13]->addBacklogItem(*task46);
    sprints[2]->addWorkItem(*task46);
    sbis.push_back(task46);

    SprintBacklogItem* task47 = new SprintBacklogItem();
    task47->setTitle("Userstory 3 realiseren");
    task47->setWorkItemNumber(47);
    task47->setDescription("Als gebruiker wil ik dat de SBI bij de juiste fase wordt getoond.");
    task47->setUser(users[0]);
    task47->setRemainingWork(8);
    task47->setCompletedWork(0);
    task47->setBaselineWork(8);

    Status *status47 = new Status();
    status47->setStatusType(*statusTypes[0]);
    task47->addStatus(*status47);

    pbis[13]->addBacklogItem(*task47);
    sprints[2]->addWorkItem(*task47);
    sbis.push_back(task47);

    SprintBacklogItem* task48 = new SprintBacklogItem();
    task48->setTitle("Userstory 4 realiseren");
    task48->setWorkItemNumber(48);
    task48->setDescription("Als gebruiker wil ik een SBI van een fase naar een andere toegestane fase kunnen slepen.");
    task48->setUser(users[1]);
    task48->setRemainingWork(12);
    task48->setCompletedWork(0);
    task48->setBaselineWork(12);

    Status *status48 = new Status();
    status48->setStatusType(*statusTypes[0]);
    task48->addStatus(*status48);

    pbis[13]->addBacklogItem(*task48);
    sprints[2]->addWorkItem(*task48);
    sbis.push_back(task48);

    SprintBacklogItem* task49 = new SprintBacklogItem();
    task49->setTitle("Userstory 13 realiseren");
    task49->setWorkItemNumber(49);
    task49->setDescription("Als gebruiker wil ik een filter tot mijn beschikking hebben op basis van de PBI die alle SBI's laat zien op het bord.");
    task49->setUser(users[4]);
    task49->setRemainingWork(15);
    task49->setCompletedWork(0);
    task49->setBaselineWork(15);

    Status *status49 = new Status();
    status49->setStatusType(*statusTypes[0]);
    task49->addStatus(*status49);

    pbis[13]->addBacklogItem(*task49);
    sprints[2]->addWorkItem(*task49);
    sbis.push_back(task49);

    SprintBacklogItem* task50 = new SprintBacklogItem();
    task50->setTitle("Userstory 14 realiseren");
    task50->setWorkItemNumber(50);
    task50->setDescription("Als gebruiker wil ik een filter tot mijn beschikking hebben op basis van gebruikersgegevens.");
    task50->setUser(users[5]);
    task50->setRemainingWork(10);
    task50->setCompletedWork(0);
    task50->setBaselineWork(10);

    Status *status50 = new Status();
    status50->setStatusType(*statusTypes[0]);
    task50->addStatus(*status50);

    pbis[13]->addBacklogItem(*task50);
    sprints[2]->addWorkItem(*task50);
    sbis.push_back(task50);

    SprintBacklogItem* task51 = new SprintBacklogItem();
    task51->setTitle("Userstory 16 realiseren");
    task51->setWorkItemNumber(51);
    task51->setDescription("Als gebruiker wil ik de volgende basisdetails op een SBI kaartje zien: titel, id met #, resterende uren, prioriteit en welke gebruiker er aan werkt.");
    task51->setUser(users[1]);
    task51->setRemainingWork(5);
    task51->setCompletedWork(0);
    task51->setBaselineWork(5);

    Status *status51 = new Status();
    status51->setStatusType(*statusTypes[0]);
    task51->addStatus(*status51);

    pbis[13]->addBacklogItem(*task51);
    sprints[2]->addWorkItem(*task51);
    sbis.push_back(task51);

    //===============Product backlog item 15=================================
    SprintBacklogItem* task52 = new SprintBacklogItem();
    task52->setTitle("Architectuur document bijwerken");
    task52->setWorkItemNumber(52);
    task52->setDescription("Het architectuur met alle gemaakte keuzes inclusief beargumentatie bijwerken.");
    task52->setUser(users[4]);
    task52->setRemainingWork(8);
    task52->setCompletedWork(0);
    task52->setBaselineWork(8);

    Status *status52 = new Status();
    status52->setStatusType(*statusTypes[0]);
    task52->addStatus(*status52);

    pbis[14]->addBacklogItem(*task52);
    sprints[2]->addWorkItem(*task52);
    sbis.push_back(task52);

    SprintBacklogItem* task53 = new SprintBacklogItem();
    task53->setTitle("Testrapport bijwerken");
    task53->setWorkItemNumber(53);
    task53->setDescription("Relevante (nieuwe) testcases toevoegen aan het testrapport.");
    task53->setUser(users[5]);
    task53->setRemainingWork(5);
    task53->setCompletedWork(0);
    task53->setBaselineWork(5);

    Status *status53 = new Status();
    status53->setStatusType(*statusTypes[0]);
    task53->addStatus(*status53);

    pbis[14]->addBacklogItem(*task53);
    sprints[2]->addWorkItem(*task53);
    sbis.push_back(task53);

    //===============Product backlog item 16=================================
    SprintBacklogItem* task54 = new SprintBacklogItem();
    task54->setTitle("Bepalen wie presenteert");
    task54->setWorkItemNumber(54);
    task54->setDescription("Bepalen wie de presentatie gaat geven.");
    task54->setUser(users[1]);
    task54->setRemainingWork(2);
    task54->setCompletedWork(0);
    task54->setBaselineWork(2);

    Status *status54 = new Status();
    status54->setStatusType(*statusTypes[0]);
    task54->addStatus(*status54);

    pbis[15]->addBacklogItem(*task54);
    sprints[2]->addWorkItem(*task54);
    sbis.push_back(task54);

    SprintBacklogItem* task55 = new SprintBacklogItem();
    task55->setTitle("Presentatie sheets maken");
    task55->setWorkItemNumber(55);
    task55->setDescription("Presentatie sheets maken voor de presentatie van de resultaten voor sprint #3.");
    task55->setUser(users[5]);
    task55->setRemainingWork(10);
    task55->setCompletedWork(0);
    task55->setBaselineWork(10);

    Status *status55 = new Status();
    status55->setStatusType(*statusTypes[0]);
    task55->addStatus(*status55);

    pbis[15]->addBacklogItem(*task55);
    sprints[2]->addWorkItem(*task55);
    sbis.push_back(task55);

    SprintBacklogItem* task56 = new SprintBacklogItem();
    task56->setTitle("Presentatie geven");
    task56->setWorkItemNumber(56);
    task56->setDescription("Het presenteren van de bereikte resultaten van sprint #3.");
    task56->setUser(users[0]);
    task56->setRemainingWork(1);
    task56->setCompletedWork(0);
    task56->setBaselineWork(1);

    Status *status56 = new Status();
    status56->setStatusType(*statusTypes[0]);
    task56->addStatus(*status56);

    pbis[15]->addBacklogItem(*task56);
    sprints[2]->addWorkItem(*task56);
    sbis.push_back(task56);

    //===============Product backlog item 17=================================
    SprintBacklogItem* task57 = new SprintBacklogItem();
    task57->setTitle("AKD versie 4");
    task57->setWorkItemNumber(57);
    task57->setDescription("AKD versie 4 maken.");
    task57->setUser(users[3]);
    task57->setRemainingWork(3);
    task57->setCompletedWork(0);
    task57->setBaselineWork(3);

    Status *status57 = new Status();
    status57->setStatusType(*statusTypes[2]);
    task57->addStatus(*status57);

    pbis[16]->addBacklogItem(*task57);
    sprints[2]->addWorkItem(*task57);
    sbis.push_back(task57);

    SprintBacklogItem* task58 = new SprintBacklogItem();
    task58->setTitle("AKD controleren");
    task58->setWorkItemNumber(58);
    task58->setDescription("AKD versie 4 controleren.");
    task58->setUser(users[0]);
    task58->setRemainingWork(1);
    task58->setCompletedWork(0);
    task58->setBaselineWork(1);

    Status *status58 = new Status();
    status58->setStatusType(*statusTypes[0]);
    task58->addStatus(*status58);

    pbis[16]->addBacklogItem(*task58);
    sprints[2]->addWorkItem(*task58);
    sbis.push_back(task58);

    SprintBacklogItem* task59 = new SprintBacklogItem();
    task59->setTitle("AKD verbeteren");
    task59->setWorkItemNumber(59);
    task59->setDescription("AKD versie 4 verbeteren.");
    task59->setUser(users[4]);
    task59->setRemainingWork(3);
    task59->setCompletedWork(0);
    task59->setBaselineWork(3);

    Status *status59 = new Status();
    status59->setStatusType(*statusTypes[0]);
    task59->addStatus(*status59);

    pbis[16]->addBacklogItem(*task59);
    sprints[2]->addWorkItem(*task59);
    sbis.push_back(task59);

    SprintBacklogItem* task60 = new SprintBacklogItem();
    task60->setTitle("AKD bespreken");
    task60->setWorkItemNumber(60);
    task60->setDescription("AKD versie 4 bespreken.");
    task60->setUser(users[2]);
    task60->setRemainingWork(1);
    task60->setCompletedWork(0);
    task60->setBaselineWork(1);

    Status *status60 = new Status();
    status60->setStatusType(*statusTypes[0]);
    task60->addStatus(*status60);

    pbis[16]->addBacklogItem(*task60);
    sprints[2]->addWorkItem(*task60);
    sbis.push_back(task60);

    //===============Product backlog item 18=================================
    SprintBacklogItem* task61 = new SprintBacklogItem();
    task61->setTitle("Userstory 2 realiseren");
    task61->setWorkItemNumber(61);
    task61->setDescription("Als gebruiker wil ik alle SBI's op het bord kunnen zien van 1 sprint.");
    task61->setUser(users[3]);
    task61->setRemainingWork(9);
    task61->setCompletedWork(0);
    task61->setBaselineWork(9);

    Status *status61 = new Status();
    status61->setStatusType(*statusTypes[0]);
    task61->addStatus(*status61);

    pbis[17]->addBacklogItem(*task61);
    sprints[2]->addWorkItem(*task61);
    sbis.push_back(task61);

    SprintBacklogItem* task62 = new SprintBacklogItem();
    task62->setTitle("Userstory 5 realiseren");
    task62->setWorkItemNumber(62);
    task62->setDescription("Als gebruiker wil ik dat als ik een SBI naar de fase Done sleep, de remaining time op 0 wordt gezet.");
    task62->setUser(users[1]);
    task62->setRemainingWork(8);
    task62->setCompletedWork(0);
    task62->setBaselineWork(8);

    Status *status62 = new Status();
    status62->setStatusType(*statusTypes[0]);
    task62->addStatus(*status62);

    pbis[17]->addBacklogItem(*task62);
    sprints[2]->addWorkItem(*task62);
    sbis.push_back(task62);

    SprintBacklogItem* task63 = new SprintBacklogItem();
    task63->setTitle("Userstory 13 realiseren");
    task63->setWorkItemNumber(63);
    task63->setDescription("Als gebruiker wil ik een filter tot mijn beschikking hebben op basis van de PBI die alle SBI's laat zien op het bord.");
    task63->setUser(users[5]);
    task63->setRemainingWork(10);
    task63->setCompletedWork(0);
    task63->setBaselineWork(10);

    Status *status63 = new Status();
    status63->setStatusType(*statusTypes[0]);
    task63->addStatus(*status63);

    pbis[17]->addBacklogItem(*task63);
    sprints[2]->addWorkItem(*task63);
    sbis.push_back(task63);

    SprintBacklogItem* task64 = new SprintBacklogItem();
    task64->setTitle("Userstory 14 realiseren");
    task64->setWorkItemNumber(64);
    task64->setDescription("Als gebruiker wil ik een filter tot mijn beschikking hebben op basis van de gebruikersgegevens.");
    task64->setUser(users[0]);
    task64->setRemainingWork(10);
    task64->setCompletedWork(0);
    task64->setBaselineWork(10);

    Status *status64 = new Status();
    status64->setStatusType(*statusTypes[0]);
    task64->addStatus(*status64);

    pbis[17]->addBacklogItem(*task64);
    sprints[2]->addWorkItem(*task64);
    sbis.push_back(task64);

    SprintBacklogItem* task65 = new SprintBacklogItem();
    task65->setTitle("Userstory 10 realiseren");
    task65->setWorkItemNumber(65);
    task65->setDescription("Als gebruiker wil ik een aparte view hebben met daarop de details van de huidig geselecteerde SBI.");
    task65->setUser(users[2]);
    task65->setRemainingWork(5);
    task65->setCompletedWork(0);
    task65->setBaselineWork(5);

    Status *status65 = new Status();
    status65->setStatusType(*statusTypes[0]);
    task65->addStatus(*status65);

    pbis[17]->addBacklogItem(*task65);
    sprints[2]->addWorkItem(*task65);
    sbis.push_back(task65);

    SprintBacklogItem* task66 = new SprintBacklogItem();
    task66->setTitle("Userstory 21 realiseren");
    task66->setWorkItemNumber(66);
    task66->setDescription("Als gebruikerw il ik aan kunnen geven wie er met een kaartje bezig is door te slepen.");
    task66->setUser(users[5]);
    task66->setRemainingWork(8);
    task66->setCompletedWork(0);
    task66->setBaselineWork(8);

    Status *status66 = new Status();
    status66->setStatusType(*statusTypes[0]);
    task66->addStatus(*status66);

    pbis[17]->addBacklogItem(*task66);
    sprints[2]->addWorkItem(*task66);
    sbis.push_back(task66);

    SprintBacklogItem* task67 = new SprintBacklogItem();
    task67->setTitle("Userstory 15 realiseren");
    task67->setWorkItemNumber(67);
    task67->setDescription("Als gebruiker wil ik de volgende eigenschappen van een SBI kunnen wijzigen: status, uren, gebruikersinformatie.");
    task67->setUser(users[3]);
    task67->setRemainingWork(12);
    task67->setCompletedWork(0);
    task67->setBaselineWork(12);

    Status *status67 = new Status();
    status67->setStatusType(*statusTypes[0]);
    task67->addStatus(*status67);

    pbis[17]->addBacklogItem(*task67);
    sprints[2]->addWorkItem(*task67);
    sbis.push_back(task67);

    //===============Product backlog item 19=================================
    SprintBacklogItem* task68 = new SprintBacklogItem();
    task68->setTitle("Architectuur document bijwerken");
    task68->setWorkItemNumber(68);
    task68->setDescription("Architectuur keuzes en beagrumentatie bijwerken.");
    task68->setUser(users[2]);
    task68->setRemainingWork(6);
    task68->setCompletedWork(0);
    task68->setBaselineWork(6);

    Status *status68 = new Status();
    status68->setStatusType(*statusTypes[0]);
    task68->addStatus(*status68);

    pbis[18]->addBacklogItem(*task68);
    sprints[2]->addWorkItem(*task68);
    sbis.push_back(task68);

    SprintBacklogItem* task69 = new SprintBacklogItem();
    task69->setTitle("Testrapport bijwerken");
    task69->setWorkItemNumber(69);
    task69->setDescription("Relevante (nieuwe) testcases toevoegen aan het testrapport.");
    task69->setUser(users[3]);
    task69->setRemainingWork(7);
    task69->setCompletedWork(0);
    task69->setBaselineWork(7);

    Status *status69 = new Status();
    status69->setStatusType(*statusTypes[0]);
    task69->addStatus(*status69);

    pbis[18]->addBacklogItem(*task69);
    sprints[2]->addWorkItem(*task69);
    sbis.push_back(task69);

    //===============Product backlog item 20=================================
    SprintBacklogItem* task70 = new SprintBacklogItem();
    task70->setTitle("Testcases bepalen");
    task70->setWorkItemNumber(70);
    task70->setDescription("Bepalen welke testcases er uitgevoerd gaan worden.");
    task70->setUser(users[5]);
    task70->setRemainingWork(10);
    task70->setCompletedWork(0);
    task70->setBaselineWork(10);

    Status *status70 = new Status();
    status70->setStatusType(*statusTypes[0]);
    task70->addStatus(*status70);

    pbis[19]->addBacklogItem(*task70);
    sprints[2]->addWorkItem(*task70);
    sbis.push_back(task70);

    SprintBacklogItem* task71 = new SprintBacklogItem();
    task71->setTitle("Testcases verdelen");
    task71->setWorkItemNumber(71);
    task71->setDescription("Bepalen wie welke testcase(s) uit gaat voeren.");
    task71->setUser(users[5]);
    task71->setRemainingWork(1);
    task71->setCompletedWork(0);
    task71->setBaselineWork(1);

    Status *status71 = new Status();
    status71->setStatusType(*statusTypes[0]);
    task71->addStatus(*status71);

    pbis[19]->addBacklogItem(*task71);
    sprints[2]->addWorkItem(*task71);
    sbis.push_back(task71);

    SprintBacklogItem* task72 = new SprintBacklogItem();
    task72->setTitle("Testcases sprint #3 uitvoeren");
    task72->setWorkItemNumber(72);
    task72->setDescription("Het uitvoeren van de testcases aan de hand van de resultaten van sprint #3.");
    task72->setUser(users[0]);
    task72->setRemainingWork(7);
    task72->setCompletedWork(0);
    task72->setBaselineWork(7);

    Status *status72 = new Status();
    status72->setStatusType(*statusTypes[0]);
    task72->addStatus(*status72);

    pbis[19]->addBacklogItem(*task72);
    sprints[2]->addWorkItem(*task72);
    sbis.push_back(task72);

    //===============Product backlog item 21=================================
    SprintBacklogItem* task73 = new SprintBacklogItem();
    task73->setTitle("Bepalen wie de eindpresentatie geeft");
    task73->setWorkItemNumber(73);
    task73->setDescription("Bepalen wie de eindpresentatie gaat geven.");
    task73->setUser(users[0]);
    task73->setRemainingWork(1);
    task73->setCompletedWork(0);
    task73->setBaselineWork(1);

    Status *status73 = new Status();
    status73->setStatusType(*statusTypes[0]);
    task73->addStatus(*status73);

    pbis[20]->addBacklogItem(*task73);
    sprints[2]->addWorkItem(*task73);
    sbis.push_back(task73);

    SprintBacklogItem* task74 = new SprintBacklogItem();
    task74->setTitle("Eindpresentatie sheets maken");
    task74->setWorkItemNumber(74);
    task74->setDescription("De eindpresentatie opbouwen.");
    task74->setUser(users[4]);
    task74->setRemainingWork(12);
    task74->setCompletedWork(0);
    task74->setBaselineWork(12);

    Status *status74 = new Status();
    status74->setStatusType(*statusTypes[0]);
    task74->addStatus(*status74);

    pbis[20]->addBacklogItem(*task74);
    sprints[2]->addWorkItem(*task74);
    sbis.push_back(task74);

    SprintBacklogItem* task75 = new SprintBacklogItem();
    task75->setTitle("Eindpresentatie geven");
    task75->setWorkItemNumber(75);
    task75->setDescription("Het presenteren van het eindresultaat.");
    task75->setUser(users[0]);
    task75->setRemainingWork(1);
    task75->setCompletedWork(0);
    task75->setBaselineWork(1);

    Status *status75 = new Status();
    status75->setStatusType(*statusTypes[0]);
    task75->addStatus(*status75);

    pbis[20]->addBacklogItem(*task75);
    sprints[2]->addWorkItem(*task75);
    sbis.push_back(task75);

    return sbis;
}
