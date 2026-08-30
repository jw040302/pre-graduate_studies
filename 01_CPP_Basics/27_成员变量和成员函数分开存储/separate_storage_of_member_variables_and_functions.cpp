#include <iostream>

class Empty
{
};

class Person
{
public:
    int m_Age;

    void showAge()
    {
        std::cout << m_Age << "\n";
    }
};

int main()
{
    std::cout << "空类占用空间：" << sizeof(Empty) << "字节\n";
    std::cout << "Person类占用空间：" << sizeof(Person) << "字节\n";

    return 0;
}
