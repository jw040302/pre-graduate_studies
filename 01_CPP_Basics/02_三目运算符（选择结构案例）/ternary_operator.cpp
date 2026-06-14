#include <iostream>
int main()
{
    int a = 10, b = 20, c = 0;

    c = (a > b ? a : b);
    std::cout << "c = " << c << std::endl;

    (a < b ? a : b) = 100;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}