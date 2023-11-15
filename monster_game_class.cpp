#include "random.h" // defines Random::mt, Random::get(), and and Random::generate()
#include <iostream>
#include <string>
#include <string_view>

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        orge,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types,
    };

    Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
        : m_type{ type }
        , m_name{ name }
        , m_roar{ roar }
        , m_hitPoints{ hitPoints }
    {
    }

    std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case dragon:      return "Dragon";
        case goblin:      return "Goblin";
        case orge:        return "Orge";
        case orc:         return "Orc";
        case skeleton:    return "Skeleton";
        case troll:       return "Troll";
        case vampire:     return "Vampire";
        case zombie:      return "Zombie";
        default:          return "not a valid monster";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
    }

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hitPoints{};
};

namespace MonsterGenerator
{
    std::string_view getName(int n)
    {
        switch (n)
        {
        case 0:  return "Blarg";
        case 1:  return "Moog";
        case 2:  return "Pksh";
        case 3:  return "Tyrn";
        case 4:  return "Mort";
        case 5:  return "Hans";
        default: return "not a valid input";
        }
    }

    std::string_view getRoar(int n)
	{
        switch (n)
        {
            case 0:  return "*ROAR*";
            case 1:  return "*peep*";
            case 2:  return "*squeal*";
            case 3:  return "*whine*";
            case 4:  return "*growl*";
            case 5:  return "*burp*";
            default: return "not a valid input";
        }
    }

    Monster generate()
    {
        return Monster{ static_cast<Monster::Type>(Random::get(0, Monster::max_monster_types - 1)), getName(Random::get(0, 5)), getRoar(Random::get(0, 5)), Random::get(0, 100)};
    }
};

int main(){
    Monster m{ MonsterGenerator::generate() };
	m.print();

    return 0;
}
