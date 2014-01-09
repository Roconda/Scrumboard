#include "defectvisitor.h"

DefectVisitor::DefectVisitor()
{
}

void DefectVisitor::visit(Defect& defect) {
    DefectList.push_back(&defect);
}

vector<Defect*>& DefectVisitor::getList() {
    return DefectList;
}
