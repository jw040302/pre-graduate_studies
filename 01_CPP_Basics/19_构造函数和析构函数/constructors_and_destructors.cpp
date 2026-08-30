#include <iostream>

class Person
{
public:
    Person()
    {
        std::cout << "构造函数被调用\n";
    }

    ~Person()
    {
        std::cout << "析构函数被调用\n";
    }
};

int main()
{
    Person p1;
    std::cout << "对象正在使用中\n";

    return 0;
}
