#pragma once
#include <string>
enum class ItemType;
class ItemDB;

class Item
{
private:
    std::string name;
    ItemType type;
    std::string skillName;
    
public:
    Item(ItemDB);
    std::string GetName() const {return name;} 
    std::string GetSkillName() const {return skillName;}
    ItemType GetType() const {return type;} 
};
