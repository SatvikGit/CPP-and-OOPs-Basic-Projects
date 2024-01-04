#include <iostream>

int factorial(int number)
{
    if (number <= 0)
        return 1;

    else
        return factorial(number - 1) * number;
}

int main(){
    for (int i = 0; i <= 7; i++)
        std::cout << factorial(i) << ' ';
    std::cout << '\n';

    return 0;
}
