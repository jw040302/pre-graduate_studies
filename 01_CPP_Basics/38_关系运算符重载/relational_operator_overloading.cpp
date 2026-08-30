#include <iostream>
#include <string>

class Person
{
private:
    std::string m_Name;
    int m_Age;

public:
    Person(std::string name, int age) : m_Name(name), m_Age(age)
    {
    }

    bool operator==(const Person &person)
    {
        return m_Name == person.m_Name && m_Age == person.m_Age;
    }

    bool operator!=(const Person &person)
    {
        return !(*this == person);
    }
};

int main()
{
    Person p1("张三", 20);
    Person p2("张三", 20);
    Person p3("李四", 22);

    std::cout << "p1和p2是否相等：" << (p1 == p2 ? "是" : "否") << "\n";
    std::cout << "p1和p3是否不等：" << (p1 != p3 ? "是" : "否") << "\n";

    return 0;
}
