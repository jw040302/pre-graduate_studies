#include <iostream>

class MyInteger
{
    friend std::ostream &operator<<(std::ostream &output, const MyInteger &number);

private:
    int m_Number;

public:
    MyInteger() : m_Number(0)
    {
    }

    MyInteger &operator++()
    {
        m_Number++;
        return *this;
    }

    MyInteger operator++(int)
    {
        MyInteger temporary = *this;
        m_Number++;
        return temporary;
    }
};

std::ostream &operator<<(std::ostream &output, const MyInteger &number)
{
    output << number.m_Number;
    return output;
}

int main()
{
    MyInteger number;

    std::cout << "前置递增：" << ++number << "\n";
    std::cout << "后置递增返回值：" << number++ << "\n";
    std::cout << "当前值：" << number << "\n";

    return 0;
}
