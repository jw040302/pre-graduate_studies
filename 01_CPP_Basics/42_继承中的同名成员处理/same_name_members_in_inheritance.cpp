#include <iostream>

class Base
{
public:
    int m_Value;

    Base() : m_Value(10)
    {
    }

    void showValue()
    {
        std::cout << "Base中的值：" << m_Value << "\n";
    }
};

class Derived : public Base
{
public:
    int m_Value;

    Derived() : m_Value(20)
    {
    }

    void showValue()
    {
        std::cout << "Derived中的值：" << m_Value << "\n";
    }
};

int main()
{
    Derived object;

    std::cout << object.m_Value << "\n";
    std::cout << object.Base::m_Value << "\n";

    object.showValue();
    object.Base::showValue();

    return 0;
}
