#include <utility>
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

template <typename T>
std::vector<T> takeInput()
{
    iuediindfck
}

int main(){
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    auto m1{ findMaxMin(v1) };
    printArray(v1);
    std::cout << "The min element has index " << m1.first << " and value " << v1[m1.first] << '\n';
    std::cout << "The max element has index " << m1.second << " and value " << v1[m1.second] << '\n' << '\n';

    auto m2{ findMaxMin(v2) };
    printArray(v2);
    std::cout << "The min element has index " << m2.first << " and value " << v2[m2.first] << '\n';
    std::cout << "The max element has index " << m2.second << " and value " << v2[m2.second] << '\n' << '\n';

    return 0;
}
