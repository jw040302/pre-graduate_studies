#include <iostream>

int main() {

  int arr[5] = {1, 3, 2, 5, 4};

  std::cout << "数组元素逆置前：" << std::endl;

  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << std::endl;
  }

  int start = 0;
  int end = sizeof(arr) / sizeof(arr[0]) - 1;

  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
  }

  std::cout << "数组元素逆置后：" << std::endl;

  for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << std::endl;
  }

  return 0;
}