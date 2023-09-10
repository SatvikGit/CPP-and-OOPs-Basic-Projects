#include <iostream>

int main(){
    char ch{};

    std::cout << "Enter a single character: ";
    std::cin >> ch;

    std::cout << "You've entered \'" << ch << "\' which has ASCII code " << static_cast<int>(ch) << '.' <<'\n';
    return 0;
}
