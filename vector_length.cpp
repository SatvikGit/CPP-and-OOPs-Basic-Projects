#include <iostream>
#include <vector>

int main(){
    std::vector<char> vec { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The array has " << vec.size() << " elements.\n";
    std::cout << vec[1];
    std::cout << vec.at(1) << '\n';
    return 0;
}
