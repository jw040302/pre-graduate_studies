#include <iostream>

class Person
{
private:
    static int m_Count;

public:
    Person()
    {
        m_Count++;
    }

    static void showCount()
    {
        std::cout << "已创建对象数量：" << m_Count << "\n";
    }
};

int Person::m_Count = 0;

int main()
{
    Person p1;
    Person p2;
    Person p3;

    Person::showCount();

    return 0;
}
