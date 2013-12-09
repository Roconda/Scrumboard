#include "pbivisitor.h"

PBIVisitor::PBIVisitor()
{
}

void PBIVisitor::visit(ProductBacklogItem& pbi){
    SBIlist.push_back(&pbi);
}

vector<ProductBacklogItem*>& PBIVisitor::getList(){
    return SBIlist;
}
