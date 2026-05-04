#pragma once
#include <string>
#include "Item.h"
#include <unordered_map>
enum class ItemType
{
    Weapon,
    Helmet,
    Armor,
    Boots,
    ETC
};

struct ItemDB
{
    
    std::string name;
    ItemType type;
    std::string skillName;
    
    
    static std::unordered_map<int, ItemDB>CreateItemDB();
    
};