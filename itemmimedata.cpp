#include "itemmimedata.h"

ItemMimeData::ItemMimeData()
{
    this->item = NULL;
    this->defect = NULL;
}

void ItemMimeData::setItemUI(ItemUI *item){
    this->item = item;
}

ItemUI* ItemMimeData::getItemUI(){
    return item;
}

void ItemMimeData::setDefectUI(DefectUI *defect){
    this->defect = defect;
}

DefectUI* ItemMimeData::getDefectUI(){
    return defect;
}
