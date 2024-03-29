#include <iostream>
#include <string>
#include <string_view>

class Fruit
{
private:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit(std::string_view name, std::string_view color)
        : m_name{ name }
        , m_color{ color }
    {
    }

    std::string_view getName() const { return m_name; }
    std::string_view getColor() const { return m_color; }
};

class Apple : public Fruit
{
// The previous constructor we used for Apple had a fixed name ("apple").
// We need a new constructor for GrannySmith to use to set the name of the fruit
protected: // protected so only derived classes can access
    Apple(std::string_view name, std::string_view color)
        : Fruit( name, color)
    {
    }

public:
    Apple(std::string_view color = "red")
        : Fruit("apple", color)
    {
    }
};

class Banana : public Fruit
{
public:
    Banana(std::string_view color = "yellow")
        : Fruit("banana", color)
    {
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
        : Apple{ "granny smith apple", "green" }
    {
    }
};

int main(){
    Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
