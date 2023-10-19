#include <iostream>

class Point2d
{
private:
    double m_x{ 0.0 };
    double m_y{ 0.0 };

public:
    Point2d(double x = 0.0, double y = 0.0)
        : m_x{ x }
        , m_y{ y }
    {
    }

    void print(Point2d point)
    {
        std::cout << "Point"
    }
};

int main(){
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    return 0;
}
