#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "Random.h"

namespace WordList
{
    std::vector<std::string_view> words{ "mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };

    std::string_view getRandomWord()
    {
        return words[Random::get<std::size_t>(0, words.size() - 1)];
    }
}

namespace Settings
{
   constexpr int wrong_guesses_allowed{6}; 
}


class Session
{
private:
    // Game session data
    std::string_view m_word { WordList::getRandomWord() };
    std::vector<bool> m_letter_guessed { std::vector<bool>(26) };
    int m_wrong_guesses{};
    std::vector<char> m_wrongly_guessed_letters{};

    std::size_t toIndex(char c) const { return static_cast<std::size_t>((c % 32)-1); }

public:
    std::string_view getWord() const { return m_word; }
    bool isLetterGuessed(char c) const { return m_letter_guessed[toIndex(c)]; }
    void setLetterGuessed(char c) { m_letter_guessed[toIndex(c)] = true; }
    void setWrongGuesses() { m_wrong_guesses++; }
    int getWrongGuesses() const { return m_wrong_guesses; }
    void setWronglyGuessedLetters(char input) { m_wrongly_guessed_letters.emplace_back(input); }
    std::vector<char> getWronglyGuessedLetters() const { return m_wrongly_guessed_letters; }
};

void printWrongGuesses(Session& s);

void draw(const Session& s)
{
    std::cout << "\n";

    std::cout << "The word: ";
    for (auto c: s.getWord()) // step through each letter of word
    {
        if (s.isLetterGuessed(c))
            std::cout << c;
        else
            std::cout << '_';
    }
}

char getGuess(Session& s)
{
    std::cout << "Enter your next letter: ";

    while (true)
    {
        char c{};
        std::cin >> c;

        // If user did something bad, try again
        if (!std::cin)
        {
            // Fix it
            std::cin.clear();
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Clear out any extraneous input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // If the user entered an invalid char, try again
        if (c < 'a' || c > 'z')
        {
            std::cout << "That wasn't a valid input.  Try again.\n";
            continue;
        }

        // If the letter was already guessed, try again
        if (s.isLetterGuessed(c))
        {
            std::cout << "You already guessed that.  Try again.\n\n";
            continue;
        }

        // If we got here, this must be a valid guess
        return c;
    }
}

bool isLetterInWord(Session& s, char input)
{
    for (auto letter : s.getWord())
    {
        if (input == letter)
        {
            return true;
        }
    }

    s.setWrongGuesses();
    s.setWronglyGuessedLetters(input);
    return false;
}

void printGuessedLetter(Session& s, char input)
{
    if (isLetterInWord(s, input))
        std::cout << "Yes, " << input << " is in the word!\n";

    else
        std::cout << "No, " << input << " is not in the word!\n";
}

void printWrongGuesses(Session& s)
{
    int wrong_guesses = s.getWrongGuesses();

    std::cout << "\tWrong Guesses: ";
    for (int i = 0; i < (Settings::wrong_guesses_allowed - wrong_guesses); i++)
    {
        std::cout << '+';
    }

    for (auto letter : s.getWronglyGuessedLetters())
    {
        std::cout << letter;
    }

    std::cout << '\n';
}

bool isWon(Session& s)
{
    for (auto letter : s.getWord())
    {
        if (!s.isLetterGuessed(letter))
            return false;
    }

    return true;
}

int main(){
    std::cout << "Welcome to C++man (a variant of Hangman)\n";
    std::cout << "To win: guess the word.  To lose: run out of pluses.\n";

    Session s{};
    std::cout << s.getWord();
    while ((s.getWrongGuesses() < Settings::wrong_guesses_allowed) && !isWon(s))
    {
        draw(s);
        printWrongGuesses(s);
        char c { getGuess(s) };
        s.setLetterGuessed(c);
        printGuessedLetter(s, c);
    }

    draw(s);

    if (isWon(s))
        std::cout << "You lost! The Word was: " << s.getWord() << '\n';

    else
        std::cout << "You Won!\n";

    return 0;
}
