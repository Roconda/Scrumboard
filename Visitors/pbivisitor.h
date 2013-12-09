#ifndef PBIVISITOR_H
#define PBIVISITOR_H

#include "../TFS/ProductBacklogItem.h"

#include <vector>

using std::vector;

class PBIVisitor : public TFSVisitor
{
public:
    PBIVisitor();
    void visit(ProductBacklogItem& pbi);
    vector<ProductBacklogItem*>& getList();

private:
    vector<ProductBacklogItem*> SBIlist;
};

#endif // PBIVISITOR_H
