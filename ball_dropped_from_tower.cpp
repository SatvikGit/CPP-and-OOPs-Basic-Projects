#include <iostream>

float getHeight()
{
    // Using float because height may be in decimal value but will not have high precision issue so didn't use a double
    float height{};
    std::cout << "Enter the height of tower in in meters: ";
    std::cin >> height;

    return height;
}

void calcHeight(float initial, int sec)
{
    constexpr float gravityConstant{9.8f};
    double height{};

    // Formula for calculating height at a given time
    height = height - (gravityConstant * sec * sec / 2);

    if (height > 0)
    std::cout << "At " << sec << " seconds, the ball is at height: " << height << " meters" << '\n';
    else
    std::cout << "At " << sec << " seconds, the ball is on ground." << '\n';
}

int main(){
    const float height{ getHeight() };

    calcHeight(height, 0);
    calcHeight(height, 1);
    calcHeight(height, 2);
    calcHeight(height, 3);
    calcHeight(height, 4);
    calcHeight(height, 5);
    return 0;
}
