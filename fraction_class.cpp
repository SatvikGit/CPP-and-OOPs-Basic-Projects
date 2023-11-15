#include <iostream>

class Fraction
{
public:
    int m_num{0};
    int m_deno{1};

public:
    void setData()
    {
        std::cout << "Enter a value for the numerator: ";
        std::cin >> m_num;

        std::cout << "Enter a value for the denominator: ";
        std::cin >> m_deno;
    }

    Fraction multFraction(const Fraction& frac2)
    {
        Fraction frac{};
        frac.m_num = m_num * frac2.m_num;
        frac.m_deno = m_deno * frac2.m_deno;
        return frac;
    }
};

int main(){
    Fraction frac1{};
    frac1.setData();

    Fraction frac2{};
    frac2.setData();
    
    std::cout << "Your fractions multiplied together: " << frac1.multFraction(frac2).m_num << '/' << frac1.multFraction(frac2).m_deno << '\n';
    return 0;
}
