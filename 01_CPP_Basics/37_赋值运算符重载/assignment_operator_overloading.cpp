#include <iostream>

class Person
{
private:
    int *m_Age;

public:
    Person(int age)
    {
        m_Age = new int(age);
    }

    ~Person()
    {
        delete m_Age;
        m_Age = nullptr;
    }

    Person &operator=(const Person &person)
    {
        if (this == &person)
        {
            return *this;
        }

        delete m_Age;
        m_Age = new int(*person.m_Age);
        return *this;
    }

    int getAge()
    {
        return *m_Age;
    }
};

int main()
{
    Person p1(20);
    Person p2(30);
    Person p3(40);

    p3 = p2 = p1;

    std::cout << p1.getAge() << " " << p2.getAge() << " " << p3.getAge() << "\n";

    return 0;
}
