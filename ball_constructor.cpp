#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
    std::string m_color{};
    double m_radius{};

public:
    // Constructor defined
    Ball(std::string_view col, double rad)
        // Member initailization list
        : m_color { col }
        , m_radius { rad }
    {
    }

    void print() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main(){
    Ball blue{ "blue", 10.0 };
	blue.print();

	Ball red{ "red", 12.0 };
	red.print();

    return 0;
}
