#include <iostream>

class Person
{
public:
    int m_Age;

    Person(int age)
    {
        m_Age = age;
    }

    Person(const Person &person)
    {
        m_Age = person.m_Age;
        std::cout << "拷贝构造函数被调用\n";
    }
};

void showPerson(Person person)
{
    std::cout << "年龄：" << person.m_Age << "\n";
}

Person createPerson()
{
    Person person(30);
    return person;
}

int main()
{
    Person p1(20);
    Person p2(p1);

    showPerson(p1);

    Person p3 = createPerson();
    std::cout << "返回对象的年龄：" << p3.m_Age << "\n";

    return 0;
}
