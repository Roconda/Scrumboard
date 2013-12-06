#ifndef SBIVISITOR_H
#define SBIVISITOR_H

#include "../TFS/SprintBacklogItem.h"
#include "../TFS/TFSVisitor.h"
using std::vector;

class SBIVisitor : public TFSVisitor
{
public:
    SBIVisitor();
    void visit(SprintBacklogItem& sbi);
    vector<SprintBacklogItem*> getList();

private:
    vector<SprintBacklogItem*> SBIlist;
};

#endif // SBIVISITOR_H
