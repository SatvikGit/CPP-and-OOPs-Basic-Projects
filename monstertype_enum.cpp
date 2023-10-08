#include <iostream>

namespace Monster
{
    enum MonsterType
    {
        orc,
        goblin,
        troll,
        orge,
        skeleton,
    };
}

int main(){
    Monster::MonsterType monster{ Monster::troll}; 
    return 0;
}
