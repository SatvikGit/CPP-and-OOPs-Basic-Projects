#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
    std::string m_color{ "black "};
    double m_radius{ 10.0 };

public:
    // Handles Ball(radius)
    Ball(double rad)
        : m_radius{ rad }
        {
            print();
        }
    
    // Handles Ball(color, radius), Ball(color), and Ball()
    Ball(std::string_view col = "black", double rad = 10.0)
        : m_color{ col }
        , m_radius{ rad }
        {
            print();
        }

    void print() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main(){
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
