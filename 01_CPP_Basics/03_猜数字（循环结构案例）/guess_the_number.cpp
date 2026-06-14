#include <iostream>
#include <ctime>

int main()
{
    std::srand((unsigned int)std::time(NULL));

    int num = 1 + std::rand() % 100;

    int guess = 0;
    std::cout << "这是一个1到100之间的随机整数,请猜测:";
    while (1)
    {
        std::cin >> guess;
        if (guess > num)
        {
            std::cout << "大了,再试一次:";
        }
        else if (guess < num)
        {
            std::cout << "小了,再试一次:";
        }
        else
        {
            std::cout << "对了!\n";
            break;
        }
    }
}