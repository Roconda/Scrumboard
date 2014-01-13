#include "workitemstatusvisitor.h"

WorkItemStatusVisitor::WorkItemStatusVisitor()
{
}

void WorkItemStatusVisitor::visit(Defect& defect) {
    for(size_t i =0; i < defect.getStatusArray().size(); i++){
        if(defect.getStatus(i)){
            this->status = defect.getStatus(i);
        }else{
            break;
        }
    }
}

void WorkItemStatusVisitor::visit(SprintBacklogItem &sbi) {
    this->status = sbi.getStatus(sbi.sizeStatus() -1);
}

Status* WorkItemStatusVisitor::getStatus(){
    return this->status;
}
