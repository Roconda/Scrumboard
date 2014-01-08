#ifndef ITEMMIMEDATA_H
#define ITEMMIMEDATA_H

#include <QMimeData>
#include "View/itemui.h"
#include "View/defectui.h"

class ItemMimeData : public QMimeData
{
public:
    ItemMimeData();
    void setItemUI(ItemUI* item);
    ItemUI* getItemUI();
    void setDefectUI(DefectUI* item);
    DefectUI* getDefectUI();

private:
    ItemUI* item;
    DefectUI* defect;
};

#endif // ITEMMIMEDATA_H
