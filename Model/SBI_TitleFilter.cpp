#include "SBI_TitleFilter.h"
#include "../TFS/SprintBacklogItem.h"
#include <QDebug>

std::vector<WorkItem*> SBI_TitleFilter::Filter(std::vector<WorkItem*> content, QString phrase)
{
    std::vector<WorkItem*> temp;

    for(std::vector<WorkItem*>::iterator it = content.begin(); it != content.end(); ++it)
    {
        WorkItem* si = *it;

        if(si)
        {
            QString db_u = QString::fromLocal8Bit(si->getTitle());

            if(db_u.contains(phrase, Qt::CaseInsensitive))
            {
                temp.push_back(si);
            }
        }
    }

    return temp;
}
