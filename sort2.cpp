#include <iostream>

void sort2(int& a, int& b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}

int main(){
    int x { 7 };
    int y { 5 };

    sort2(x, y);
    std::cout << x << ' ' << y << '\n';

    sort2(x, y);
    std::cout << x << ' ' << y << '\n';

    return 0;
}
