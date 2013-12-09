#include "pbivisitor.h"

PBIVisitor::PBIVisitor()
{
}

void PBIVisitor::visit(ProductBacklogItem& pbi) {
    PBIList.push_back(&pbi);
}

vector<ProductBacklogItem*>& PBIVisitor::getList() {
    return PBIList;
}
