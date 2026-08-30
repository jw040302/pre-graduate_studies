#include <iostream>

class Person
{
private:
    int m_Age;

public:
    Person(int age) : m_Age(age)
    {
    }

    void showAge()
    {
        std::cout << "年龄：" << m_Age << "\n";
    }
};

int main()
{
    Person *person = nullptr;

    if (person == nullptr)
    {
        std::cout << "空指针不能访问对象成员\n";
    }

    Person p1(20);
    person = &p1;
    person->showAge();

    return 0;
}
