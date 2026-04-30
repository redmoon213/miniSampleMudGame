#pragma once
#include <string>
#include <unordered_map>

struct ItemDB
{
    std::string name;
    
    
public:
    
    std::unordered_map<int, ItemDB>CreateItemDB();
};
