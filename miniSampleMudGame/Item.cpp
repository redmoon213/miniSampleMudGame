#include "Item.h"

Item::Item():itemCode(0), itemName(""), itemType(ItemType::ETC){}

Item::Item(int itemCode, std::string itemName, ItemType itemType)
    :itemCode(itemCode), itemName(itemName), itemType(itemType){
}

Item::~Item(){}


void Item::UsingItem()
{
    
}
