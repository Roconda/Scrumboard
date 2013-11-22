#include "itemmimedata.h"

ItemMimeData::ItemMimeData()
{

}

void ItemMimeData::setItemUI(ItemUI *item){
    this->item = item;
}

ItemUI* ItemMimeData::getItemUI(){
    return item;
}
