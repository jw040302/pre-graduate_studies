#include <iostream>
#include <string>

int main() {
    // 1. 定义三只小猪的体重变量
    int pigA = 45;
    int pigB = 55;
    int pigC = 50;

    std::cout << "--- 三只小猪称体重赛跑 ---" << std::endl;
    std::cout << "小猪A的体重是: " << pigA << " kg\n";
    std::cout << "小猪B的体重是: " << pigB << " kg\n";
    std::cout << "小猪C的体重是: " << pigC << " kg\n";
    std::cout << "--------------------------" << std::endl;

    // 2. 开始做逻辑判断，找出最重的小猪
    if (pigA > pigB && pigA > pigC) {
        std::cout << "🏆 裁判宣布：小猪A最重！" << std::endl;
    } 
    else if (pigB > pigA && pigB > pigC) {
        std::cout << "🏆 裁判宣布：小猪B最重！" << std::endl;
    } 
    else if (pigC > pigA && pigC > pigB) {
        std::cout << "🏆 裁判宣布：小猪C最重！" << std::endl;
    } 
    else {
        // 兜底机制：如果有两只或者三只小猪一样重，就会走到这里
        std::cout << "🤝 裁判宣布：有小猪一样重，平局！" << std::endl;
    }

    return 0;
}