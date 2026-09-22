#include <cstring>
#include <fstream>
#include <iostream>

struct Person
{
    char name[32];
    int age;
};

int main()
{
    Person person = {};
    std::strcpy(person.name, "张三");
    person.age = 20;

    std::ofstream output("person.dat", std::ios::binary);

    if (!output.is_open())
    {
        std::cout << "二进制文件写入失败\n";
        return 1;
    }

    output.write(reinterpret_cast<const char *>(&person), sizeof(person));
    output.close();

    Person loadedPerson = {};
    std::ifstream input("person.dat", std::ios::binary);

    if (!input.is_open())
    {
        std::cout << "二进制文件读取失败\n";
        return 1;
    }

    input.read(reinterpret_cast<char *>(&loadedPerson), sizeof(loadedPerson));
    input.close();

    std::cout << "姓名：" << loadedPerson.name << "\n";
    std::cout << "年龄：" << loadedPerson.age << "\n";

    return 0;
}
