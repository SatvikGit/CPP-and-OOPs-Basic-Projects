#include <iostream>

int getInput()
{
    int input{};

    std::cout << "Enter the number: ";
    std::cin >> input;
    return input; // Returns the value entered by user
}

int doubleNumber(int num)
{
    int doubleNum = num * 2;
    return doubleNum;
}

int main(){
    int num{ getInput() };

    std:: cout << "Double that number is: " << doubleNumber(num) << '\n';
    return 0;
}
