#include "SBI_UsernameFilter.h"
#include "../TFS/SprintBacklogItem.h"
#include "../TFS/User.h"

std::vector<WorkItem*> SBI_UsernameFilter::Filter(std::vector<WorkItem*> content, QString phrase)
{
    std::vector<WorkItem*> temp;

    for(std::vector<WorkItem*>::iterator it = content.begin(); it != content.end(); ++it)
    {
        WorkItem* si = *it;

        if(si && si->getUser())
        {
            QString db_u = QString::fromLocal8Bit(si->getUser()->getName());

            if(db_u.contains(phrase, Qt::CaseInsensitive))
            {
                temp.push_back(si);
            }
        }
    }

    return temp;
}
