#include "pbicreator.h"

PBICreator::PBICreator()
{
}

vector<ProductBacklogItem*> PBICreator::Create(vector<Sprint*> sprints)
{
    vector<ProductBacklogItem*> pbis;

    ProductBacklogItem *pbi1 = new ProductBacklogItem();
    pbi1->setTitle("Klasse diagram");
    pbi1->setPriority(94);
    sprints[0]->addWorkItem(*pbi1);
    pbis.push_back(pbi1);

    ProductBacklogItem *pbi2 = new ProductBacklogItem();
    pbi2->setTitle("Contact");
    pbi2->setPriority(100);
    sprints[0]->addWorkItem(*pbi2);
    pbis.push_back(pbi2);

    ProductBacklogItem *pbi3 = new ProductBacklogItem();
    pbi3->setTitle("Design keuzes");
    pbi3->setPriority(90);
    sprints[0]->addWorkItem(*pbi3);
    pbis.push_back(pbi3);

    ProductBacklogItem *pbi4 = new ProductBacklogItem();
    pbi4->setTitle("Realisatie");
    pbi4->setPriority(96);
    sprints[0]->addWorkItem(*pbi4);
    pbis.push_back(pbi4);

    ProductBacklogItem *pbi5 = new ProductBacklogItem();
    pbi5->setTitle("Documentatie");
    pbi5->setPriority(84);
    sprints[0]->addWorkItem(*pbi5);
    pbis.push_back(pbi5);

    ProductBacklogItem *pbi6 = new ProductBacklogItem();
    pbi6->setTitle("Testing");
    pbi6->setPriority(80);
    sprints[0]->addWorkItem(*pbi6);
    pbis.push_back(pbi6);

    ProductBacklogItem *pbi7 = new ProductBacklogItem();
    pbi7->setTitle("Presentatie");
    pbi7->setPriority(100);
    sprints[0]->addWorkItem(*pbi7);
    pbis.push_back(pbi7);


    //=================================  SPRINT 2 ================================
    ProductBacklogItem *pbi8 = new ProductBacklogItem();
    pbi8->setTitle("Klasse diagram");
    pbi8->setPriority(94);
    sprints[1]->addWorkItem(*pbi8);
    pbis.push_back(pbi8);

    ProductBacklogItem *pbi9 = new ProductBacklogItem();
    pbi9->setTitle("Realisatie");
    pbi9->setPriority(96);
    sprints[1]->addWorkItem(*pbi9);
    pbis.push_back(pbi9);

    ProductBacklogItem *pbi10 = new ProductBacklogItem();
    pbi10->setTitle("Documentatie");
    pbi10->setPriority(80);
    sprints[1]->addWorkItem(*pbi10);
    pbis.push_back(pbi10);

    ProductBacklogItem *pbi11 = new ProductBacklogItem();
    pbi11->setTitle("Testing");
    pbi11->setPriority(90);
    sprints[1]->addWorkItem(*pbi11);
    pbis.push_back(pbi11);

    ProductBacklogItem *pbi12 = new ProductBacklogItem();
    pbi12->setTitle("Presentatie");
    pbi12->setPriority(100);
    sprints[1]->addWorkItem(*pbi12);
    pbis.push_back(pbi12);

    //=================================  SPRINT 3 ================================
    ProductBacklogItem *pbi13 = new ProductBacklogItem();
    pbi13->setTitle("Klasse diagram");
    pbi13->setPriority(92);
    sprints[2]->addWorkItem(*pbi13);
    pbis.push_back(pbi13);

    ProductBacklogItem *pbi14 = new ProductBacklogItem();
    pbi14->setTitle("Realisatie");
    pbi14->setPriority(100);
    sprints[2]->addWorkItem(*pbi14);
    pbis.push_back(pbi14);

    ProductBacklogItem *pbi15 = new ProductBacklogItem();
    pbi15->setTitle("Documentatie");
    pbi15->setPriority(88);
    sprints[2]->addWorkItem(*pbi15);
    pbis.push_back(pbi15);

    ProductBacklogItem *pbi16 = new ProductBacklogItem();
    pbi16->setTitle("Testing");
    pbi16->setPriority(84);
    sprints[2]->addWorkItem(*pbi16);
    pbis.push_back(pbi16);

    ProductBacklogItem *pbi17 = new ProductBacklogItem();
    pbi17->setTitle("Presentatie");
    pbi17->setPriority(100);
    sprints[2]->addWorkItem(*pbi17);
    pbis.push_back(pbi17);


    //=================================  SPRINT 4 ================================
    ProductBacklogItem *pbi18 = new ProductBacklogItem();
    pbi18->setTitle("Klasse diagram");
    pbi18->setPriority(92);
    sprints[3]->addWorkItem(*pbi18);
    pbis.push_back(pbi18);

    ProductBacklogItem *pbi19 = new ProductBacklogItem();
    pbi19->setTitle("Realisatie");
    pbi19->setPriority(100);
    sprints[3]->addWorkItem(*pbi19);
    pbis.push_back(pbi19);

    ProductBacklogItem *pbi20 = new ProductBacklogItem();
    pbi20->setTitle("Documentatie");
    pbi20->setPriority(88);
    sprints[3]->addWorkItem(*pbi20);
    pbis.push_back(pbi20);

    ProductBacklogItem *pbi21 = new ProductBacklogItem();
    pbi21->setTitle("Testing");
    pbi21->setPriority(84);
    sprints[3]->addWorkItem(*pbi21);
    pbis.push_back(pbi21);

    ProductBacklogItem *pbi22 = new ProductBacklogItem();
    pbi22->setTitle("Presentatie");
    pbi22->setPriority(100);
    sprints[3]->addWorkItem(*pbi22);
    pbis.push_back(pbi22);

    return pbis;
}
