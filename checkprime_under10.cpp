#include <iostream>

int main(){
    int num{};

    std::cout << "Enter a number between 1 and 9: ";
    std::cin >> num;

    if (num == 2)
    std::cout << "Prime number" << '\n';

    else if (num == 3)
    std::cout << "Prime number" << '\n';

    else if (num == 5)
    std::cout << "Prime number" << '\n';

    else if (num == 7)
    std::cout << "Prime number" << '\n';

    else
    std::cout << "Not a Prime number" << '\n';

    return 0;
}
