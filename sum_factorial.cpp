#include <iostream>

int sumTo(int x)
{
    int sum{ 0 };

    for (int i{ 1 }; i <= x; i++)
    {
        sum += i;
    }
    return sum;
}

int main(){
    int num{};

    std::cout << "Enter the number: ";
    std::cin >> num;

    std::cout << "Value of sum till " << num << ": " << sumTo(num) << '\n';
    return 0;
}
