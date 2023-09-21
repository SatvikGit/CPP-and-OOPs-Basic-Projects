#include <iostream>

void fizzbuzz(int x)
{
    for (int i{ 1 }; i <= x; i++)
    {
        bool printed{ false };

        if ((i % 3) == 0)
        {
            std::cout << "fizz";
            printed = true;
        }

        if ((i % 5) == 0)
        {
            std::cout << "buzz";
            printed = true;
        }

        if ((i % 7) == 0)
        {
            std::cout << "pop";
            printed = true;
        }

        if (!printed)
            std::cout << i;
        std::cout << '\n';
    }
}

int main(){
    int num{};

    std::cout << "Enter the Number: ";
    std::cin >> num;
    fizzbuzz(num);
    return 0;
}
