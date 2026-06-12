#include <iostream>

void bubble_sort(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void print_array(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << std::endl;
  }
}

int main() {
  int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
  int len = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, len);
  print_array(arr, len);

  return 0;
}