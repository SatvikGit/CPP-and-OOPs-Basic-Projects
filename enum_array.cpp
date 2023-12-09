#include <iostream>
#include <string>
#include <string_view>
#include <array>

namespace Animal
{
    enum Animals
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals,
    };

    struct Data
    {
       std::string_view name{};
       int legs{};
       std::string_view sound{}; 
    };

    constexpr std::array<Data, max_animals> dataArray{{ { "chicken", 2, "cluck"}, { "dog", 4, "woof"}, { "cat", 4, "meow"}, { "elephant", 4, "pawoo"}, { "duck", 2, "quack"}, { "snake", 0, "hissss"} }};
    static_assert(std::size(dataArray) == max_animals);
}

int getInput(const std::array<Animal::Data, Animal::max_animals>& arr)
{
    std::string input_animal{};
    std::cout << "Enter an animal: ";
    std::cin >> input_animal;

    bool found{};
    int animal_val{-1};
    for (auto animal : arr)
    {
        std::string_view name = animal.name;
        animal_val++;

        if (name == input_animal)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        animal_val = -1;
        std::cout << "That animal couldn't be found.\n";
    }

    else
    {
        std::cout << "A " << arr[animal_val].name << " has " << arr[animal_val].legs << " legs and says " << arr[animal_val].sound << ".\n";
    }

    return animal_val;
}

void printData(const std::array<Animal::Data, Animal::max_animals>& arr, int val)
{
    std::cout << "\nHere is the data for the rest of the animals: \n";
    for (std::size_t i = 0; i < Animal::max_animals; i++)
    {
        if (static_cast<int>(i) == val)
            continue;

        else
            std::cout << "A " << arr[i].name << " has " << arr[i].legs<< " legs and says " << arr[i].sound << ".\n";
    }
}

int main(){
    int input{ getInput(Animal::dataArray) };
    printData(Animal::dataArray, input);

    return 0;
}
