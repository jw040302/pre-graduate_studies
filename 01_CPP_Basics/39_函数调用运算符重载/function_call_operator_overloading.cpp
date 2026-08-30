#include <iostream>
#include <string>

class Printer
{
public:
    void operator()(std::string text)
    {
        std::cout << text << "\n";
    }
};

class Adder
{
public:
    int operator()(int first, int second)
    {
        return first + second;
    }
};

int main()
{
    Printer printer;
    printer("函数调用运算符被调用");

    std::cout << "计算结果：" << Adder()(10, 20) << "\n";

    return 0;
}
