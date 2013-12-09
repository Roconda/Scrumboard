#ifndef PBIVISITOR_H
#define PBIVISITOR_H

#include "../TFS/TFSVisitor.h"
#include "../TFS/ProductBacklogItem.h"
using std::vector;

class PBIVisitor : public TFSVisitor
{
public:
    PBIVisitor();
    void visit(ProductBacklogItem& pbi);
    vector<ProductBacklogItem*>& getList();

private:
    vector<ProductBacklogItem*> PBIList;
};

#endif // PBIVISITOR_H
