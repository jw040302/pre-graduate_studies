#include <iostream>

class Student
{
public:
    std::string m_Name;
    int m_Id;

    void showStudent()
    {
        std::cout << "姓名： " << m_Name << "\n学号： " << m_Id << std::endl;
    }

    void setName(std::string name)
    {
        m_Name = name;
    }

    void setId(int id)
    {
        m_Id = id;
    }
};

int main()
{
    Student s1;
    s1.setName("张三");
    s1.setId(1);
    s1.showStudent();

    Student s2;
    s2.m_Name = "李四";
    s2.m_Id = 2;
    s2.showStudent();

    return 0;
}