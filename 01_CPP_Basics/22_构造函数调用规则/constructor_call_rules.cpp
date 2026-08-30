#include <iostream>

class Person
{
public:
    int m_Age;

    Person(int age)
    {
        m_Age = age;
        std::cout << "有参构造函数被调用\n";
    }
};

int main()
{
    Person p1(20);
    Person p2(p1);

    std::cout << "p1的年龄：" << p1.m_Age << "\n";
    std::cout << "p2的年龄：" << p2.m_Age << "\n";

    return 0;
}
