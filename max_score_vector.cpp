#include <iostream>
#include <vector>

template <typename T>
int findMax(const std::vector<T> arr)
{
    int max{ arr[0] };
    for (std::size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int main()
{
    std::vector testScore { 84, 92, 76, 81, 56 };
    std::cout << "The max score is: " << findMax(testScore) << '\n'; // prints 92

    return 0;
}
