#include <cassert>
#include <utility>
#include <iostream>
#include <vector>

namespace Items
{
    enum Name
    {
        health_potions,
        torches,
        arrows,
        max_items, // value = 3
    };
}

void countItems(const std::vector<int>& vec)
{
    int items = 0;
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        items += vec[i];
    }

    std::cout << "You have total " << items << " items\n";
}

void printItems(const std::vector<int>& vec)
{
    std::cout << "You have " << vec[0] << " health potion";
    if (vec[0] > 1)
        std::cout << 's';
    std::cout << '\n';

    std::cout << "You have " << vec[1] << " torch";
    if (vec[1] > 1)
        std::cout << "es";
    std::cout << '\n';

    std::cout << "You have " << vec[2] << " arrow";
    if (vec[2] > 1)
        std::cout << 's';
    std::cout << '\n';
}

int main(){
    std::vector num_items{1, 5, 10};

    assert(Items::max_items == num_items.size());
    printItems(num_items);
    countItems(num_items);
    return 0;
}
