#include "ItemConsumable.h"

ItemConsumable::ItemConsumable(int itemCodeNew, std::string itemNameNew, ItemType itemTypeNew ,int amountNew)
    :Item(itemCodeNew, itemNameNew, itemTypeNew), amount(amountNew)
{}

void ItemConsumable::UsingItem()
{
    
}

void ItemConsumable::UsingItem(Player&)
{
    std::cout<<"<TEST UsingItem overloading\n";
}
