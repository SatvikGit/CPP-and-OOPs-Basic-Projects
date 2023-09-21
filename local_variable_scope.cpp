#include <iostream>

int main(){
    int smaller{};
    int larger{};

    std::cout << "Enter an integer: ";
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    std::cin >> larger;

    if (smaller >= larger) // temp created here to temporarily store value
    {
        std::cout << "Swapping the values" << '\n';

        int temp{};
        temp = smaller;
        smaller = larger;
        larger = temp;
    } // temp is destroyed here

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
}
