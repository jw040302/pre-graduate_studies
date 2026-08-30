#include <iostream>

class Person
{
public:
    int m_Age;

    Person()
    {
        m_Age = 0;
        std::cout << "默认构造函数\n";
    }

    Person(int age)
    {
        m_Age = age;
        std::cout << "有参构造函数\n";
    }

    Person(const Person &person)
    {
        m_Age = person.m_Age;
        std::cout << "拷贝构造函数\n";
    }
};

int main()
{
    Person p1;
    Person p2(20);
    Person p3(p2);

    std::cout << p1.m_Age << " " << p2.m_Age << " " << p3.m_Age << "\n";

    return 0;
}
