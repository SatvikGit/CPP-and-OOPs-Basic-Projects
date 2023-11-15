#include <iostream>
#include <vector>

int main(){
    int first{};
    int second{};
    int third{};

    std::cout << "Enter 3 integers: ";
    std::cin >> first >> second >> third;
    std::vector<int> integers{ first, second, third };

    int sum{};
    int product{1};
    for (int i = 0; i < 3; i++)
    {
        sum += integers[i];
        product = product * integers[i];
    }

    std::cout << "The sum is: " << sum << '\n';
    std::cout << "The product is: " << product << '\n';

    return 0;
}
