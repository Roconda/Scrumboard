#include "sbivisitor.h"
#include "../TFS/SprintBacklogItem.h"

SBIVisitor::SBIVisitor()
{
}

void SBIVisitor::visit(SprintBacklogItem& sbi){
    SBIlist.push_back(&sbi);
}

vector<SprintBacklogItem*> SBIVisitor::getList(){
    return SBIlist;
}
