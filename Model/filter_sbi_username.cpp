#include "filter_sbi_username.h"
#include "../TFS/User.h"
#include "../TFS/WorkItem.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

Filter_SBI_Username::Filter_SBI_Username(FilterDecorator *component, QString phrase)
    : FilterOption(component, phrase) {}

void Filter_SBI_Username::Filter(std::vector<WorkItem *> &content)
{
    #ifdef QT_DEBUG
    qDebug() << "Filter_SBI_Username";
    #endif

    this->component->Filter(content);

    #ifdef QT_DEBUG
    qDebug() << "Passed username...";
    #endif

    std::vector<WorkItem*> temp;

    for(std::vector<WorkItem*>::iterator it = content.begin(); it != content.end(); ++it)
    {
        WorkItem* si = *it;

        if(si && si->getUser())
        {
            QString db_u = QString::fromLocal8Bit(si->getUser()->getName());

            if(db_u.contains(this->phrase, Qt::CaseInsensitive))
            {
                temp.push_back(si);
            }
        }
    }

    content = temp;
}
