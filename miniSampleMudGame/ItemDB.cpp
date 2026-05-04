#include "ItemDB.h"

std::unordered_map<int, ItemDB>CreateItemDB()
{
    std::unordered_map<int, ItemDB> db;
    
    
    //1~100 : 장비
    db[1] = {"나무검"};
    db[2] = {"철검"};
    //101~200 소모품
    db[101] = {""};
    //201~300 화폐
    db[201] = {"골드"};
    //301~400 지도
    db[301] ={"묘지"};
    
    return db;
}