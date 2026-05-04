#include "Player.h"
#include "Monster.h"
#include "SkillDB.h"
#include "ItemDB.h"

Player::Player(std::string name, int str, int dex, int intel, int lv)
    :Character(name, str, dex, intel), level(lv), exp(0), maxExp(level*50)
{
    auto db = SkillDB::CreateSkillDB();
    auto itemDB = ItemDB::CreateItemDB();
    
    skillList.push_back(UserSkills(db["강타"]));
    skillList.push_back(UserSkills(db["회전베기"]));
    equipment.fill(nullptr);
    equipment.at(static_cast<int>(EquipSlot::Weapon)) = new Item(itemDB[1]);
    inventory.push_back(new Item(itemDB[21]));
}

void Player::GainExp(int expGain)
{
    exp += expGain;
    while (exp >= maxExp)
    {
        LevelUp();
        exp -= maxExp;
        maxExp = level * 50;
    }
}

void Player::LevelUp()
{
    level++;
    int input;
    std::cout <<"레벨업!" << level-1 << " -> " << level <<"\n";
    for (int i = 0; i<2; i++)
    {
        std::cout <<">> 올릴 능력치를 입력하세요 | 남은 포인트 : " << 2-i <<"\n";
        std::cout <<"1.힘, 2.민첩 3.지능\n";
        std::cin>>input;
        switch (input)
        {
        case 1: strength ++;break;
        case 2: dexterity ++;break;
        case 3: intelligence ++;break;
        }
    }
    StatSetting();
    hp=maxHp;
}

int Player::AttackNormal()
{
    mp += intelligence; 
    if (mp>maxMp) mp = maxMp;
    
    return attackDamage;
}

void Player::Loot(std::vector<int> rewardItem)
{
    std::cout << "아이템을 획득하였습니다!\n";
    
    for (int item: rewardItem)
    {
        inventory[item]++;
        std::cout<< itemList[item] << "\n";
       
    }
}

void Player::Loot(int rewardItem)
{/*
    inventory[rewardItem]++;
    std::cout << "아이템을 획득하였습니다!\n";
    std::cout<< itemList[rewardItem] << "\n";*/
}

int Player::UsingItem()
{
    ////
   return 0;
}

void Player::Cooling()
{
    for (auto& it: skillList)
    {
        it.DecreaseCooltime();
    }
}

bool Player::CheckSkillCooldown()
{
    for (const auto& it : skillList)
    {
        if (it.IsReady()) return true;
    }
    
    return false;
}

int Player::ActivateSkill(std::vector<std::unique_ptr<Monster>>& monsters)
{
    std::vector<Monster> targetList;
    srand(time(NULL));
    
   for (auto& it : skillList)
   {
       if (it.IsReady())
       {
           it.SetCurrentCooltime(it.GetBaseCooltime());
           
           //싱글타겟 멀티타겟 체크
           for (auto& skills : it.GetSkillEffects())
           {
               if (skills.type==EffectType::SingleTarget)
               {
                   targetList.push_back(*monsters[rand()%monsters.size()]);
               }
               else if (skills.type==EffectType::MultiTarget)
               {
                   for (auto& i : monsters)
                   targetList.push_back(*i);
               }
           }
           
           //데미지 or 힐 체크
           for (auto& skills : it.GetSkillEffects())
           {
               if (skills.type==EffectType::Damage)
               {
                   for (auto& target: targetList)
                   {
                       target.TakeDamage(skills.value + dexterity * 1.5);
                       
                   }
               }
               
               if (skills.type==EffectType::Heal)
               {
                   Heal(skills.value);
               }
           }
           
           std::cout << "[" << it.GetName() << "] !! \n"; 
           break;
       }
   }
    return 0;
}


void Player::Equip()
{
    system("cls"); // 화면 깔끔하게 정리
    std::cout << "=============================================================\n";
    std::cout << "<착용중인 장비>\n";
    
    // 1. 현재 장비창 출력
    for (int i = 0; i < equipment.size(); ++i) {
        std::string slotName;
        switch (static_cast<EquipSlot>(i)) {
            case EquipSlot::Weapon: slotName = "1_[무기]"; break;
            case EquipSlot::Helmet: slotName = "2_[투구]"; break;
            case EquipSlot::Armor:  slotName = "3_[갑옷]"; break;
            case EquipSlot::Boots:  slotName = "4_[신발]"; break;
            default: continue;
        }
        
        std::cout << slotName << " : " << (equipment[i] ? equipment[i]->GetName() : "빈 슬롯") << "\n";
    }
    std::cout << "=============================================================\n";

    // 2. 슬롯 선택
    int slotInput = 0;
    std::cout << "변경할 슬롯 번호를 입력하세요 (취소: 0): ";
    std::cin >> slotInput;
    if (slotInput <= 0 || slotInput > static_cast<int>(EquipSlot::Max)) return;

    int selectedSlotIdx = slotInput - 1; // 배열 인덱스로 변환
    ItemType targetType = static_cast<ItemType>(selectedSlotIdx);

    // 3. 해당 슬롯에 맞는 인벤토리 아이템 필터링
    std::cout << "\n[ 장착 가능한 아이템 목록 ]\n";
    
    // 필터링된 아이템의 '원본 인벤토리 인덱스'를 저장할 벡터
    std::vector<int> filteredIndices; 

    int displayNum = 1;
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i]->GetType() == targetType) {
            std::cout << displayNum << ". " << inventory[i]->GetName() << "\n";
            filteredIndices.push_back(i); // 원본 인덱스 저장
            displayNum++;
        }
    }

    if (filteredIndices.empty()) {
        std::cout << "장착 가능한 아이템이 인벤토리에 없습니다.\n";
        system("pause");
        return;
    }

    // 4. 아이템 선택 및 교체
    int itemInput = 0;
    std::cout << "장착할 아이템 번호를 입력하세요 (취소: 0): ";
    std::cin >> itemInput;

    if (itemInput <= 0 || itemInput > filteredIndices.size()) return;

    int inventoryIdx = filteredIndices[itemInput - 1]; // 선택한 번호로 원본 인덱스 추출
    Item* itemToEquip = inventory[inventoryIdx];

    // 5. 장착 로직 (교체)
    if (equipment[selectedSlotIdx] != nullptr) {
        // 기존 장비가 있으면 다시 인벤토리에 넣기 (원하는 기획에 따라 선택)
        inventory.push_back(equipment[selectedSlotIdx]);
    }

    // 장비창에 넣고 인벤토리에서 제거
    equipment[selectedSlotIdx] = itemToEquip;
    inventory.erase(inventory.begin() + inventoryIdx);

    std::cout << "\n장착이 완료되었습니다!\n";
    system("pause");
}