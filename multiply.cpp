#include <iostream>

int main(){
    int num{};

    std::cout << "Enter the number: ";
    std:: cin >> num;

    // We have directly calculated double of number inside cout statement as we dont have store double in another variable to save memory
    std:: cout << "Double that number is: " << num * 2 << '\n';
    return 0;
}
