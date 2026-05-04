#include "Item.h"

#include "ItemDB.h"


Item::Item(ItemDB db)
    :name(db.name), type(db.type), skillName(db.skillName)
{
    
}
