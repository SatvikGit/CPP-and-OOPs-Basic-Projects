#include <iostream>

enum class Animal
{
    chicken,
    goat,
    cat,
    dog,
    duck,
};

std::string_view getAnimalName(Animal a)
{
    switch (a)
    {
    case (Animal::chicken):
        return "chicken";

    case (Animal::goat):
        return "goat";

    case (Animal::cat):
        return "cat";

    case (Animal::dog):
        return "dog";

    case (Animal::duck):
        return "duck";
    
    default:
        return "Enter a valid animal";
    }
}

int printNumberofLegs(Animal a)
{
    switch (a)
    {
    case (Animal::chicken):
        return 2;

    case (Animal::goat):
        return 4;

    case (Animal::cat):
        return 4;

    case (Animal::dog):
        return 4;

    case (Animal::duck):
        return 2;
    
    default:
        return 0;
    }
}

int main(){
    Animal animal{ Animal::chicken };
    std::cout << "A " << getAnimalName(animal) << " has " << printNumberofLegs(animal) << " legs.\n";
    return 0;
}
