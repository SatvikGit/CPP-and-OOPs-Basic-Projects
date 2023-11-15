#include <iostream>
#include <limits>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr)
{
    for (std::size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

template <typename T>
void findIndex(const std::vector<T>& arr, int value)
{
    bool found{};

    for (std::size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == value)
        {
            std::cout << "The number " << value << " has index " << i << '\n';
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "The number " << value << " was not found\n";
    }
}

int getValidNumber()
{
    int value{};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> value;

        // if the user entered an invalid character
        if (!std::cin)
            std::cin.clear(); // reset any error flags

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any extra characters in the input buffer (regardless of whether we had an error or not)

    } while (value < 1 || value > 9);

    return value;
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    int value{ getValidNumber() };
    printArray(arr); // use function template to print array
    findIndex(arr, value);

    return 0;
}
