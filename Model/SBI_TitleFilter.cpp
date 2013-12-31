#include "SBI_TitleFilter.h"
#include "../TFS/SprintBacklogItem.h"
#include <QDebug>

std::vector<SprintBacklogItem*> SBI_TitleFilter::Filter(std::vector<SprintBacklogItem*> content, QString phrase)
{
    std::vector<SprintBacklogItem*> temp;

    for(std::vector<SprintBacklogItem*>::iterator it = content.begin(); it != content.end(); ++it)
    {
        SprintBacklogItem* si = *it;

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
