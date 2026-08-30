#include <iostream>

class Person
{
    friend std::ostream &operator<<(std::ostream &output, const Person &person);

private:
    int m_Age;

public:
    Person(int age) : m_Age(age)
    {
    }
};

std::ostream &operator<<(std::ostream &output, const Person &person)
{
    output << "年龄：" << person.m_Age;
    return output;
}

int main()
{
    Person p1(20);
    std::cout << p1 << "\n";

    return 0;
}
