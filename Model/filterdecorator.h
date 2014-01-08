#ifndef FILTERDECORATOR_H
#define FILTERDECORATOR_H

class FilterDecorator
{
public:
    virtual void Filter(std::vector<WorkItem*>& content, QString phrase) = 0;
};

#endif // FILTERDECORATOR_H
