#include <fstream>
#include <iostream>

int main()
{
    std::ofstream output("study_notes.txt");

    if (!output.is_open())
    {
        std::cout << "文件打开失败\n";
        return 1;
    }

    output << "姓名：张三\n";
    output << "课程：C++核心编程\n";
    output << "进度：文件操作\n";

    output.close();

    std::cout << "文件写入完成\n";

    return 0;
}
