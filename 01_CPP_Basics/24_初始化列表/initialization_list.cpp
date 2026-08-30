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

    void showInfo()
    {
        std::cout << "姓名：" << m_Name << "\n";
        std::cout << "年龄：" << m_Age << "\n";
    }
};

int main()
{
    Person p1("张三", 20);
    p1.showInfo();

    return 0;
}
