#include <iostream>
#include <string>
#include <string_view>
#include <array>

struct Item
{
    std::string_view name{};
    int gold{};
};

int main(){
    constexpr ::array<Item, 4> items {{ {"sword", 5}, {"dagger", 3}, {"club", 2}, {"spear", 7} }};

    for (auto item : items)
    {
        std::cout << "A " << item.name << " costs " << item.gold << " gold" << '\n';
    }

    return 0;
}
