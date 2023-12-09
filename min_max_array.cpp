#include <utility>
#include <limits>
#include <iostream>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> findMaxMin(const std::vector<T>& vec)
{
    std::size_t min_index{};
    std::size_t max_index{};

    for (std::size_t i = 0; i < vec.size(); i++)
    {
        if (vec[min_index] > vec[i])
            min_index = i;

        else if (vec[max_index] < vec[i])
            max_index = i;
    }

    return { min_index, max_index };
}

template <typename T>
void printArray(const std::vector<T>& vec)
{
    std::cout << "With array (";
    bool comma{};

    for (auto i : vec)
    {
        if (comma)
            std::cout << ',';
        
        std::cout << ' ' << i;
        comma = true; 
    } 

    std::cout << " ) :\n";

}

std::vector<int> takeInput()
{
    std::vector<int> vec{};
    int input{};

    std::cout << "Enter numbers to add (use -1 to stop): ";
    while (true)
    {
        std::cin >> input;
        if (input == -1)
            break;

        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
            continue;
        }

        vec.emplace_back(input);
    }

    return vec;
}

int main(){
    std::vector v{ takeInput() };

    auto m{ findMaxMin(v) };
    printArray(v);
    std::cout << "The min element has index " << m.first << " and value " << v[m.first] << '\n';
    std::cout << "The max element has index " << m.second << " and value " << v[m.second] << '\n' << '\n';

    return 0;
}
