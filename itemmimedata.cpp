#include "itemmimedata.h"

/**
 * @brief Create a ItemMimeData object and sets the custom variables to NULL
 */
ItemMimeData::ItemMimeData()
{
    this->item = NULL;
    this->defect = NULL;
}

/**
 * @brief set a ItemUI member in the mimedata for exchange during Drag and Drop
 * @param ItemUI* item
 */
void ItemMimeData::setItemUI(ItemUI *item){
    this->item = item;
}

/**
 * @brief Returns the ItemUI* that has been dragged
 * @return ItemUI*
 */
ItemUI* ItemMimeData::getItemUI(){
    return item;
}

/**
 * @brief set a DefectUI member in the mimedata for exchange during Drag and Drop
 * @param DefectUI* item
 */
void ItemMimeData::setDefectUI(DefectUI *defect){
    this->defect = defect;
}

/**
 * @brief Returns the DefectUI* that has been dragged
 * @return DefectUI*
 */
DefectUI* ItemMimeData::getDefectUI(){
    return defect;
}
