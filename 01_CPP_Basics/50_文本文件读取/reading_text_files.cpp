#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream input("study_notes.txt");

    if (!input.is_open())
    {
        std::cout << "文件不存在，请先运行文本文件写入案例\n";
        return 1;
    }

    std::string line;

    while (std::getline(input, line))
    {
        std::cout << line << "\n";
    }

    input.close();

    return 0;
}
