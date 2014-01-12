#ifndef FILTERDECORATOR_H
#define FILTERDECORATOR_H

#include <vector>
#include <string>
#include <Qstring>

// forward declarations
class WorkItem;

class FilterDecorator
{
public:
    virtual void Filter(std::vector<WorkItem*>& content) = 0;
};

#endif // FILTERDECORATOR_H
