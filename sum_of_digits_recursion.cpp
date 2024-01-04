#include <iostream>

int sum(int n)
{
    if (n < 10)
    {
        return n;
    }

    else
    {
        return sum(n / 10) + (n % 10);
    }

}

int main(){
    int num{};
    std::cout << "Enter integer: ";
    std::cin >> num;

    std::cout << sum(num) << '\n';

    return 0;
}
