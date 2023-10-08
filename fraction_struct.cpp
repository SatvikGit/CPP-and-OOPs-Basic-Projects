#include <iostream>

struct Fraction
{
    int num{0};
    int deno{1};
};

Fraction getData()
{
    Fraction temp{};

    std::cout << "Enter a value for the numerator: ";
    std::cin >> temp.num;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> temp.deno;

    return temp;
}

Fraction multFraction(const Fraction& frac1, const Fraction& frac2)
{
    Fraction frac{};

    frac.num = frac1.num * frac2.num;
    frac.deno = frac1.deno * frac2.deno;

    return frac;
}

int main(){
    Fraction frac1{ getData() };
    std::cout << '\n';
    Fraction frac2{ getData() };
    
    std::cout << "Your fractions multiplied together: " << multFraction(frac1, frac2).num << '/' << multFraction(frac1, frac2).deno << '\n';
    return 0;
}
