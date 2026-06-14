#include <ctime>
#include <iostream>
#include <string>

struct Student {
  std::string sName;
  int score;
};

struct Teacher {
  std::string tName;
  struct Student sArray[5];
};

void allocatteSpace(struct Teacher tArray[], int len) {
  std::string nameSeed = "ABCDE";

  for (int i = 0; i < len; i++) {
    tArray[i].tName = "Teacher_";
    tArray[i].tName += nameSeed[i];

    for (int j = 0; j < 5; j++) {
      tArray[i].sArray[j].sName = "Student_";
      tArray[i].sArray[j].sName += nameSeed[j];

      int random = rand() % 61 + 40;
      tArray[i].sArray[j].score = random;
    }
  }
}

void printInfo(struct Teacher tArray[], int len) {
  for (int i = 0; i < len; i++) {
    std::cout << "老师姓名： " << tArray[i].tName << std::endl;

    for (int j = 0; j < 5; j++) {
      std::cout << "\t学生姓名：" << tArray[i].sArray[j].sName << "\t考试分数："
                << tArray[i].sArray[j].score << std::endl;
    }
  }
}

int main() {
  srand((unsigned int)time(NULL));

  struct Teacher tArray[3];
  int len = sizeof(tArray) / sizeof(tArray[0]);
  
  allocatteSpace(tArray, len);
  printInfo(tArray, len);
  
  return 0;
}