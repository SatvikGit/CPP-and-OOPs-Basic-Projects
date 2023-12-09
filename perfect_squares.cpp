#include <iostream>

constexpr int g_perfect_squares[] {0, 1, 4, 9};

int main(){
    int number{};

    while (true)
    {
        std::cout << "Enter a single digit integer, or -1 to quit: ";
        std::cin >> number;
        
        if (number == -1)
        {
            std::cout << "Bye\n\n";
            break;
        }
        
        else if (number > 0 && number < 10)
        {
            bool found{};
            for (const auto square : g_perfect_squares)
            {
                if (number == square)
                {
                    found = true;
                    std::cout << number << " is a perfect square\n\n";
                    break;
                }
            }

            if (!found)
            {
                std::cout << number << " is not a perfect square\n\n";
            }
        }
    }
    
    return 0;
}
