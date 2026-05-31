#include <iostream>

int main() {
  int num = 100;

  do {
    int a = 0, b = 0, c = 0; // 个位、十位、百位
    a = num % 10;            // 个位
    b = num / 10 % 10;       // 十位
    c = num / 100;           // 百位

    if (a * a * a + b * b * b + c * c * c == num) {
      std::cout << num << std::endl;
    }

    num++;
  } while (num < 1000);

  return 0;
}