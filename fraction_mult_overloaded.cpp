#include <iostream>
#include <limits>
#include <numeric> // for std::gcd

class Fraction
{
private:
    int m_num{0};
    int m_deno{1};

public: 
    Fraction(int num = 0, int deno = 1)
        : m_num{ num }
        , m_deno{ deno }
    {
        // We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		reduce();
    }

    void print() const 
    { 
        std::cout << m_num << '/' << m_deno << '\n';
    }

    void reduce()
	{
		int gcd{ std::gcd(m_num, m_deno) };
		if (gcd)
		{
			m_num /= gcd;
			m_deno /= gcd;
		}
	}

    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);
    friend std::istream& operator>>(std::istream& in, Fraction& f);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    Fraction f{ f1.m_num * f2.m_num, f1.m_deno * f2.m_deno};
    return f;
}

Fraction operator*(const Fraction& f1, int value)
{
    Fraction f{ f1.m_num * value, f1.m_deno};
    return f;
}

Fraction operator*(int value, const Fraction& f1)
{
    Fraction f{ f1.m_num * value, f1.m_deno};
    return f;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    char ignore{};

    // Overwrite the values of f1
    in >> f.m_num >> ignore >> f.m_deno;
    
    // Ignore anything else
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Since we overwrite the existing f1, we need to reduce again
	f.reduce();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.m_num << '/' << f.m_deno << ' ';
    return out;
}

int main(){
    Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}
