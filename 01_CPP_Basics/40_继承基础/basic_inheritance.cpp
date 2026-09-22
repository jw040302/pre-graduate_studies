#include <iostream>
#include <string>

class Person
{
public:
    std::string m_Name;

protected:
    int m_Age;

private:
    int m_Id;

public:
    Person(std::string name, int age, int id)
        : m_Name(name), m_Age(age), m_Id(id)
    {
    }
};

class Student : public Person
{
public:
    Student(std::string name, int age, int id)
        : Person(name, age, id)
    {
    }

    void showInfo()
    {
        std::cout << "姓名：" << m_Name << "\n";
        std::cout << "年龄：" << m_Age << "\n";
    }
};

class Teacher : protected Person
{
public:
    Teacher(std::string name, int age, int id)
        : Person(name, age, id)
    {
    }

    void showInfo()
    {
        std::cout << "教师：" << m_Name << "，年龄：" << m_Age << "\n";
    }
};

int main()
{
    Student student("张三", 20, 1001);
    student.m_Name = "李四";
    student.showInfo();

    Teacher teacher("王老师", 35, 2001);
    teacher.showInfo();

    return 0;
}
