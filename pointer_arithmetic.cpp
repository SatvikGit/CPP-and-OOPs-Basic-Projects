#include <iostream>

void printCString(const char* str, int length)
{
    const char* ptr{ str + length };
    for (; ptr >= str; ptr--)
    {
        std::cout << *ptr;
    }

    std::cout << '\n';
}

int main(){
    std::string str{ "Hello World!" }; 
    printCString("Hello World!", str.length());

    return 0;
}
