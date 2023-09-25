#include <iostream>
#include <random>

int guess(int iteration)
{
    int val{};
    std::cout << "Guess #" << iteration << ": ";
    std::cin >> val;
    return val;
}

bool check_guess(int guess, int rand)
{
    bool right{};

    if (guess > rand)
    {
        std::cout << "Your guess is too high. \n";
        right = false;
    }

    else if (guess < rand)
    {
        std::cout << "Your guess is too low. \n";
        right = false;
    }

    else
    {
        std::cout << "Correct! You Win! \n";
        right = true;
    }

    return right;
}

char ask_again()
{
    char again{};
    std::cout << "Would you like to play again (y/n)? ";
    std::cin >> again;

    if (again != 'y' && again != 'n')
        ask_again();

    return again;    
}

int main(){
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<int> nums{1, 100};

    char play_again{ 'y' };

    while (play_again ==  'y')
    {
        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is. \n";
        int rand = nums(mt);
        for (int i = 1; i < 8; i++)
        {
            if ( check_guess(guess(i), rand))
            break;

            else if (i == 7)
            std::cout << "Sorry, you lose. The correct number was " << rand << '\n';
        }

        play_again = ask_again();
    }

    return 0;
}
