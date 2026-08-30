#include <iostream>
#include <string>

class Person
{
private:
    std::string m_Name;
    int m_Age;
    std::string m_Password;

public:
    void setName(std::string name)
    {
        m_Name = name;
    }

    std::string getName()
    {
        return m_Name;
    }

    void setAge(int age)
    {
        if (age < 0 || age > 150)
        {
            m_Age = 0;
            return;
        }

        m_Age = age;
    }

    int getAge()
    {
        return m_Age;
    }

    void setPassword(std::string password)
    {
        m_Password = password;
    }
};

int main()
{
    Person p1;

    p1.setName("张三");
    p1.setAge(20);
    p1.setPassword("123456");

    std::cout << "姓名：" << p1.getName() << "\n";
    std::cout << "年龄：" << p1.getAge() << "\n";

    return 0;
}
