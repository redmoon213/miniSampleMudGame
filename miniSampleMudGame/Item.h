#pragma once
#include <string>

enum class ItemType
{
    WEAPON, ARMOR, CONSUMABLE, ETC
};

class Item
{
private: 
    int itemCode;
    std::string itemName;
    int amount;
    //int amountInInventory;
    ItemType itemType;
    
public:
    Item();
    virtual ~Item();
    Item(int itemCode, std::string itemName, ItemType itemType);
    int GetItemCode() const {return itemCode;}
    std::string GetItemName() const{return itemName;}
    ItemType GetItemType() const{return itemType;}
    virtual void UsingItem();
};
