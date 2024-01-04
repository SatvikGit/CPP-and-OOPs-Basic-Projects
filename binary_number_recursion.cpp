#include <iostream>
#include <vector>

void convert(unsigned int num)
{
    if (num > 1)
        convert(num / 2);
    std::cout << num % 2;
}

int main(){
    int num{};
    std::cout << "Enter an integer: ";
    std::cin >> num;
 
    convert(static_cast<unsigned int>(num));
    std::cout << '\n';

    return 0;
}
