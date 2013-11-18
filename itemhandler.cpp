#include "itemhandler.h"

void ItemHandler::moveItem(ItemUI *item){
    scrumboard->moveItem(item);
}

void ItemHandler::moveItem(ItemUI *item, QPoint pos){
    scrumboard->moveItem(item,pos);
}

void ItemHandler::setScrumboard(ScrumboardWidget *board){
    scrumboard = board;
}
