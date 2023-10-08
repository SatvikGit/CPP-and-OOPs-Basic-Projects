#include <iostream>

struct Ad
{
    int number{};
    double percentage_clicked{};
    double avg_revenue{};
};

Ad getData()
{
    Ad temp{};

    std::cout << "Enter number of times ad watched: ";
    std::cin >> temp.number;
    std::cout << "Enter Percentage of users clicked on ad: ";
    std::cin >> temp.percentage_clicked;
    std::cout << "Enter Average earnings per ad: ";
    std::cin >> temp.avg_revenue;

    return temp;
}

void printandCalculate(const Ad& ad)
{
    std::cout << "Number of times watched: " << ad.number << '\n';
    std::cout << "Percentage of users clicked: " << ad.percentage_clicked << '\n';
    std::cout << "Average earnings per ad: " << ad.avg_revenue << '\n';
    std::cout << "Earning for day: " << ad.number * ad.percentage_clicked * ad.avg_revenue << '\n';
}

int main(){
    Ad ad{ getData() };
    printandCalculate(ad);
    return 0;
}
