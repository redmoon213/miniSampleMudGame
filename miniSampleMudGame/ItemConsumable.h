#pragma once
#include "Item.h"
#include "Monster.h"
#include "Player.h"

class ItemConsumable : public Item
{
private:
    int amount;
public:
    ItemConsumable(int itemCode, std::string itemName, ItemType itemType, int amount = 0);
    void UsingItem() override;
    void UsingItem(Player&);
    //int GetAmount() const{return amount;}
 
};
