#include <iostream>

class Person
{
private:
    int *m_Height;

public:
    Person(int height)
    {
        m_Height = new int(height);
    }

    Person(const Person &person)
    {
        m_Height = new int(*person.m_Height);
    }

    ~Person()
    {
        delete m_Height;
        m_Height = nullptr;
    }

    int getHeight()
    {
        return *m_Height;
    }

    void setHeight(int height)
    {
        *m_Height = height;
    }
};

int main()
{
    Person p1(180);
    Person p2(p1);

    p2.setHeight(175);

    std::cout << "p1的身高：" << p1.getHeight() << "\n";
    std::cout << "p2的身高：" << p2.getHeight() << "\n";

    return 0;
}
