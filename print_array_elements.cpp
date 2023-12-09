#include <iostream>
#include <array>

int main(){
    constexpr std::array word{'h', 'e', 'l', 'l', 'o'};

    constexpr int length{ word.size() };
    std::cout << "The length is " << length << '\n';
    std::cout << word[1] << word.at(1) << std::get<1>(word) << '\n';
    
    return 0;
}
