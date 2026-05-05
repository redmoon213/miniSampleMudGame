#include "ItemDB.h"

std::unordered_map<int, ItemDB> ItemDB::CreateItemDB()
{
    std::unordered_map<int, ItemDB> db;
    
    
    //1~100 : 장비
    db[1] = {"나무검",ItemType::Weapon, "강타"};
    db[2] = {"철검", ItemType::Weapon,"강타"};
    db[3] = {"흡혈귀의검",ItemType::Weapon, "흡혈의강타"};
    
    db[21] = {"가죽투구",ItemType::Helmet,"응급처치"};
    db[22] = {"철투구",ItemType::Helmet,""};
    db[23] = {"백금투구",ItemType::Helmet,""};
    
    db[41] ={"가죽갑옷",ItemType::Armor, ""};
    db[42] ={"철갑옷",ItemType::Armor, ""};
    db[43] ={"백금갑옷",ItemType::Armor, ""};
    
    //101~200 소모품
    db[101] = {""};
    //201~300 화폐
    db[201] = {"골드"};
    //301~400 지도
    db[301] ={"묘지"};
    
    return db;
}
