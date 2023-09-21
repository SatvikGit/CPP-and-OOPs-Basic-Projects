#include <iostream>

int getint()
{
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;
    return x;
}

char getopr()
{
    char c{};
    std::cout << "Enter mathematical operation: ";
    std::cin >> c;
    return c;
}

int main(){
    int a{ getint() };
    int b{ getint() };

    char opr{ static_cast<char>(getopr()) };

    switch (opr)
    {
        case '+':
            std::cout << a << " + " << b << " = " << a+b << '\n';
            break;

        case '-':
            std::cout << a << " - " << b << " = " << a-b << '\n';
            break;

        case '*':
            std::cout << a << " * " << b << " = " << a*b << '\n';
            break;

        case '/':
            float div;
            div = static_cast<float>(a) / static_cast<float>(b);

            std::cout << a << " / " << b << " = " << div << '\n';
            break;

        case '%':
            std::cout << a << " % " << b << " = " << a%b << '\n';
            break;

        default:
            std::cout << "Enter a valid mathematical operation\n";
    }
    return 0;
}
