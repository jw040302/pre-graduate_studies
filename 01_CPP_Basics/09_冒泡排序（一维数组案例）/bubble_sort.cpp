#include <iostream>

int main()
{

  int arr[9] = {4, 2, 8, 0, 5, 7, 1, 3, 9};

  std::cout << "排序前： " << std::endl;
  for (int i = 0; i < 9; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  std::cout << "排序后： " << std::endl;
  for (int i = 0; i < 9; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}