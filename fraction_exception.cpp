#include <iostream>
#include <stdexcept>
#include <exception>

class Fraction
{
private:
    int m_num{};
    int m_deno{1};

public:
    Fraction(int num = 0, int deno = 1)
        : m_num{ num }
        , m_deno{ deno }
    {
        if (m_deno == 0)
            throw std::runtime_error("Invalid Denominator");      
    }

    void print() const
    {
        std::cout << "Your fraction is: " << m_num << '/' << m_deno << '\n';
    }
};

int main(){
    int num{};
    std::cout << "Enter numerator: ";
    std::cin >> num;

    int deno{};
    std::cout << "Enter denominator: ";
    std::cin >> deno;

    try
    {
        Fraction f{num, deno};
        f.print();
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
