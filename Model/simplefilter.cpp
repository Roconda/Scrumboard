#include "simplefilter.h"
#include <QDebug>

SimpleFilter::SimpleFilter()
{
}

void SimpleFilter::Filter(std::vector<WorkItem*>& content)
{
    qDebug() << "SimpleFilter";
}
