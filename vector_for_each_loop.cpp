#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main(){
    using namespace std::literals;
    std::vector names{ "Alex"sv, "Betty"sv, "Caroline"sv, "Dave"sv, "Emily"sv, "Fred"sv, "Greg"sv, "Holly"sv };

    std::string input{};
    std::cout << "Enter a name: ";
    std::cin >> input;

    bool found{};
    for (const auto& name : names)
    {
        if (name == input)
            found = true;
    }

    if (found)
        std::cout << input << " was found.\n";

    else
        std::cout << input << " was not found.\n";
        
    return 0;
}
