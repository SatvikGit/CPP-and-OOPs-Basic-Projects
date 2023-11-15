#include <iostream>
#include <vector>

template <typename T>
void printElement(const std::vector<T>& vec, int index)
{
    if (index > (static_cast<int>(vec.size()) - 1) || index < 0)
        std::cout << "Invalid index\n";

    else
        std::cout << "The element has value " << vec[index] << '\n';
}

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
