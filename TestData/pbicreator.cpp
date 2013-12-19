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

    return pbis;
}
