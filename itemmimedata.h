#ifndef ITEMMIMEDATA_H
#define ITEMMIMEDATA_H

#include <QMimeData>
#include "View/itemui.h"

class ItemMimeData : public QMimeData
{
public:
    ItemMimeData();
    void setItemUI(ItemUI* item);
    ItemUI* getItemUI();

private:
    ItemUI* item;
};

#endif // ITEMMIMEDATA_H
