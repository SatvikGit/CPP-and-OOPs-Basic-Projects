#include <array>
#include <iostream>

template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
    bool first_element{};

    std::cout << "The array (";

    for (std::size_t i = 0; i < N; i++)
    {
        if (first_element)
            std::cout << ", ";

        std::cout << arr[i];
        first_element = true;
    }

    std::cout << ") has length " << N << '\n';
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
