#ifndef WORKITEMSTATUSVISITOR_H
#define WORKITEMSTATUSVISITOR_H

#include "../TFS/TFSVisitor.h"
#include "../TFS/Defect.h"
#include "../TFS/SprintBacklogItem.h"
#include "../TFS/Status.h"

class WorkItemStatusVisitor : public TFSVisitor
{
public:
    WorkItemStatusVisitor();
    void visit(Defect& defect);
    void visit(SprintBacklogItem& sbi);
    Status* getStatus();

private:
    Status* status;
};

#endif // WORKITEMSTATUSVISITOR_H
