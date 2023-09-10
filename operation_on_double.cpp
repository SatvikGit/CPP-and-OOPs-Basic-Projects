#include <iostream>

int main(){
    double num1{};
    double num2{};

    std::cout << "Enter a double number: ";
    std::cin >> num1;

    std::cout << "Enter a double number: ";
    std::cin >> num2;

    char operation{};
    std::cout << "Enter one of the following: +, -, * or /: ";
    std::cin >> operation;

    if (operation == '+')
    std::cout << num1 << ' ' << operation << ' ' << num2 <<  " = " << num1 + num2 << '\n';

    else if (operation == '-')
    std::cout << num1 << ' ' << operation << ' ' << num2 <<  " = " << num1 - num2 << '\n';

    else if (operation == '*')
    std::cout << num1 << ' ' << operation << ' ' << num2 <<  " = " << num1 * num2 << '\n';

    else if (operation == '/')
    std::cout << num1 << ' ' << operation << ' ' << num2 <<  " = " << num1 / num2 << '\n';

    return 0;
}
