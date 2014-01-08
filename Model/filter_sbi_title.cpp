#include "filter_sbi_title.h"
#include "filteroption.h"
#include <QDebug>

Filter_SBI_Title::Filter_SBI_Title(FilterDecorator* component) : FilterOption(component) {}

virtual void Filter_SBI_Title::Filter(std::vector<WorkItem*>& content, QString phrase)
{
    component->Filter(content, phrase);

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

    content = temp;
}
