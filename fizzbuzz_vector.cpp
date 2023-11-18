#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

void fizzbuzz(int number)
{
    using namespace std::literals::string_view_literals;

    const std::vector divisors { 3, 5, 7, 11, 13, 17, 19 };
	const std::vector words { "fizz"sv, "buzz"sv, "pop"sv, "bang"sv, "jazz"sv, "pow"sv, "boom"sv };

    assert(std::size(divisors) == std::size(words) && "fizzbuzz: array sizes don't match");

    // Loop through each number between 1 and number (inclusive)
    for (int i = 1; i <= number; i++)
    {
        bool is_div{};

        for (std::size_t j = 0; j < divisors.size(); j++)
        {
            // Check the current number against each possible divisor
            if ((i % divisors[j]) == 0)
            {
                std::cout << words[j];
                is_div = true;
            }
        }

        // If there were no divisors
        if (!is_div)
            std::cout << i;

        std::cout << '\n';
    }
}

int main(){
    fizzbuzz(150);
    return 0;
}
