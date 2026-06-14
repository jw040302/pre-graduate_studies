#include <iostream>

int main()
{
    double pig1 = 0;
    double pig2 = 0;
    double pig3 = 0;

    std::cout << "请输入小猪1的体重(单位:kg):";
    std::cin >> pig1;
    std::cout << "请输入小猪2的体重(单位:kg):";
    std::cin >> pig2;
    std::cout << "请输入小猪3的体重(单位:kg):";
    std::cin >> pig3;

    std::cout << "小猪1的体重是: " << pig1 << "kg\n";
    std::cout << "小猪2的体重是: " << pig2 << "kg\n";
    std::cout << "小猪3的体重是: " << pig3 << "kg\n";

    if (pig1 > pig2 && pig1 > pig3)
    {
        std::cout << "小猪1最重\n";
    }
    else if (pig2 > pig1 && pig2 > pig3)
    {
        std::cout << "小猪2最重\n";
    }
    else if (pig3 > pig1 && pig3 > pig2)
    {
        std::cout << "小猪3最重\n";
    }
    else
    {
        std::cout << "无法确定" << std::endl;
    }

    return 0;
}