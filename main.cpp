#include <iostream>
#define Day 7//定义
int main() {
    const int month = 12;//常量,不可改变值
    std::cout << "Hello, ROS 2 and Ubuntu!,一周总共有" << Day << "天,一年总共有" << month << "个月" << std::endl;
    auto 冠军数 = 4;//自动类型推断,可以改变值,可以是中文
    std::cout << "SIPG拿过 "<< 冠军数 <<" 个中超冠军\n";
    char str1[] = "上海海港，";//字符串数组
    std::cout << str1;
    std::string str2 = "势不可挡！";//字符串对象
    std::cout << str2 << std::endl;
    // 设定一个布尔变量，代表今年有没有夺冠
    bool is_champion = true; 

    // 计算机走到这里开始做阅读理解：如果 (夺冠了) 
    if (is_champion) {
        std::cout << "上海海港，势不可挡！" << std::endl;
    } 
    // 否则 (没夺冠)
    else {
        std::cout << "继续努力，明年再战！" << std::endl;
    }
    return 0;
}