#include <iostream>

class Person
{
private:
    int m_Age;
    mutable int m_VisitCount;

public:
    Person(int age) : m_Age(age), m_VisitCount(0)
    {
    }

    void showInfo() const
    {
        m_VisitCount++;
        std::cout << "年龄：" << m_Age << "\n";
        std::cout << "访问次数：" << m_VisitCount << "\n";
    }
};

int main()
{
    const Person p1(20);
    p1.showInfo();
    p1.showInfo();

    return 0;
}
