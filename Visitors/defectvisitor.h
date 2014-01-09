#ifndef DEFECTVISITOR_H
#define DEFECTVISITOR_H

#include "../TFS/TFSVisitor.h"
#include "../TFS/Defect.h"
#include <vector>
using std::vector;

class DefectVisitor : public TFSVisitor
{
public:
    DefectVisitor();
    void visit(Defect& defect);
    vector<Defect*>& getList();

private:
    vector<Defect*> DefectList;
};

#endif // DEFECTVISITOR_H




