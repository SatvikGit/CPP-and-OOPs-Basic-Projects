#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType
{
    org,
    dragon,
    orc,
    giantSpider,
    slime,
};

struct Monster
{
    MonsterType type{};
    std::string_view name{};
    int health{};
};

constexpr std::string_view getMonsterType(MonsterType m)
{
    switch (m)
    {
    case (MonsterType::org): return "Org";
    case (MonsterType::dragon): return "Dragon";
    case (MonsterType::orc): return "Orc";
    case (MonsterType::giantSpider): return "Giant Spider";
    case (MonsterType::slime): return "Slime";

    default:
        return "Unknown";
    }
}

void printMonster(const Monster& mon)
{
    std::cout << "This " << getMonsterType(mon.type) << " is named " << mon.name << " and has " << mon.health << " health. \n";
}

int main(){
    Monster m1{ MonsterType::org, "Torg", 145 };
    Monster m2{ MonsterType::slime, "Blurp", 23 };

    printMonster(m1);
    printMonster(m2);
    
    return 0;
}
