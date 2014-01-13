#include "simplefilter.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

SimpleFilter::SimpleFilter()
{
}

void SimpleFilter::Filter(std::vector<WorkItem*>& content)
{
    #ifdef QT_DEBUG
    qDebug() << "SimpleFilter";
    #endif
}
