#include <iostream>
#include <string>

class Phone
{
public:
    std::string m_Brand;

    Phone(std::string brand) : m_Brand(brand)
    {
        std::cout << "Phone构造函数被调用\n";
    }
};

class Person
{
public:
    std::string m_Name;
    Phone m_Phone;

    Person(std::string name, std::string brand) : m_Name(name), m_Phone(brand)
    {
        std::cout << "Person构造函数被调用\n";
    }
};

int main()
{
    Person p1("张三", "华为");

    std::cout << p1.m_Name << "使用" << p1.m_Phone.m_Brand << "手机\n";

    return 0;
}
