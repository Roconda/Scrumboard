#include "UsernameFilter.h"
#include "../TFS/SprintBacklogItem.h"
#include "../TFS/User.h"
#include <QDebug>

std::vector<SprintBacklogItem*> UsernameFilter::Filter(std::vector<SprintBacklogItem*> content, QString phrase)
{
    std::vector<SprintBacklogItem*> temp;

    for(std::vector<SprintBacklogItem*>::iterator it = content.begin(); it != content.end(); ++it)
    {
        SprintBacklogItem* si = *it;

        if(si && si->getUser())
        {
            QString db_u = QString::fromLocal8Bit(si->getUser()->getName());

            if(QString::compare(phrase, db_u, Qt::CaseInsensitive) == 0)
            {
                //qDebug() << QString(phrase + " == " + db_u);
                temp.push_back(si);
            }
        }
    }

    return temp;
}
