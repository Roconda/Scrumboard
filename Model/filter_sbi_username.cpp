#include "filter_sbi_username.h"
#include "filteroption.h"

Filter_SBI_Username::Filter_SBI_Username(FilterDecorator* component) : FilterOption(component) {}

virtual void Filter_SBI_Username::Filter(std::vector<WorkItem*>& content, QString phrase)
{
    component->Filter(content, phrase);

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

    content = temp;
}
