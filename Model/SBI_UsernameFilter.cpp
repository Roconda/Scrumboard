#include "SBI_UsernameFilter.h"
#include "../TFS/SprintBacklogItem.h"
#include "../TFS/User.h"
#include <QDebug>

std::vector<SprintBacklogItem*> SBI_UsernameFilter::Filter(std::vector<SprintBacklogItem*> content, QString phrase)
{
    std::vector<SprintBacklogItem*> temp;

    for(std::vector<SprintBacklogItem*>::iterator it = content.begin(); it != content.end(); ++it)
    {
        SprintBacklogItem* si = *it;

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
