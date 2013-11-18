#ifndef ITEMHANDLER_H
#define ITEMHANDLER_H

#include "View/itemui.h"
#include "View/scrumboardwidget.h"

class ItemHandler
{
public:
    static ItemHandler& getInstance()
    {
        static ItemHandler instance;
        return instance;
    }

    void setScrumboard(ScrumboardWidget *board);
    void moveItem(ItemUI *item);
    void moveItem(ItemUI *item, QPoint pos);

private:
    ItemHandler() {};
    ItemHandler(ItemHandler const&);
    void operator=(ItemHandler const&);

    ScrumboardWidget* scrumboard;
};

#endif // ITEMHANDLER_H
