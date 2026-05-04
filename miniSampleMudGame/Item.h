#pragma once
#include <string>

enum class ItemType
{
    Weapon,
    Armor,
    Helmet,
    Boots,
    ETC
};
class Item
{
private:
    std::string name;
    ItemType type;
    
    
public:
    Item(std::string name, ItemType type);
    std::string GetName(){return name;}
    ItemType GetType(){return type;} 
};
