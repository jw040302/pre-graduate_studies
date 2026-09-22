#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base构造函数\n";
    }

    ~Base()
    {
        std::cout << "Base析构函数\n";
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived构造函数\n";
    }

    ~Derived()
    {
        std::cout << "Derived析构函数\n";
    }
};

int main()
{
    Derived object;

    return 0;
}
