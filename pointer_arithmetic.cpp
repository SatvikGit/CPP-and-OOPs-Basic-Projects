#include <iostream>

void printCString(const char* str)
{
    for (; *str == '\0'; str++)
    {
        std::cout << *str;
    }

    std::cout << '\n';
}

int main(){
    printCString("Hello World!");

    return 0;
}
