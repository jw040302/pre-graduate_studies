#include <iostream>
#include <string>

int main() {
  int scores[3][3] = {{100, 100, 100}, {90, 50, 100}, {60, 70, 80}};
  std::string names[3] = {"张三", "李四", "王五"};

  for (int i = 0; i < 3; i++) {
    int sum = 0;
    for (int j = 0; j < 3; j++) {
      sum += scores[i][j];
      std::cout << scores[i][j] << "\t";
    }
    std::cout << names[i] << " 的总分为：" << sum << std::endl;
  }

  return 0;
}