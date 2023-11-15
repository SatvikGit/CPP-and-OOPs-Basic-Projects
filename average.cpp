#include <iostream>
#include <cstdint> // for fixed width integers

class Average
{
private:
    std::int32_t m_sum{ 0 };
    std::int8_t m_num{ 0 };

public:
    Average()
    {
    }

    Average operator+= (int value);
    friend std::ostream& operator<< (std::ostream& out, const Average& avg);
};

Average Average::operator+= (int value)
{
    // Increment our total by the new number
    m_sum += value;
    // And increase the count by 1
    ++m_num;

    // return *this in case someone wants to chain +='s together
    return *this;
}

std::ostream& operator<< (std::ostream& out, const Average& avg)
{
    out << static_cast<double>(avg.m_sum) / avg.m_num;
    return out;
}

int main(){
    Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

    return 0;
}
