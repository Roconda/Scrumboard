#include "filter_sbi_title.h"
#include "../TFS/WorkItem.h"

#ifdef QT_DEBUG
#include <QDebug>
#endif

Filter_SBI_Title::Filter_SBI_Title(FilterDecorator *component, QString phrase)
    : FilterOption(component, phrase) {}

void Filter_SBI_Title::Filter(std::vector<WorkItem *> &content)
{
    #ifdef QT_DEBUG
    qDebug() << "Filter_SBI_Title";
    #endif

    this->component->Filter(content);

    #ifdef QT_DEBUG
    qDebug() << "Passed title...";
    #endif

    std::vector<WorkItem*> temp;

    for(std::vector<WorkItem*>::iterator it = content.begin(); it != content.end(); ++it)
    {
        WorkItem* si = *it;

        if(si)
        {
            QString db_u = QString::fromLocal8Bit(si->getTitle());

            if(db_u.contains(this->phrase, Qt::CaseInsensitive))
            {
                temp.push_back(si);
            }
        }
    }

    content = temp;
}
