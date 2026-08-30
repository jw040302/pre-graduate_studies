#include <iostream>
#include <string>

class Person
{
public:
    std::string m_Name;

protected:
    std::string m_Car;

private:
    int m_Password;

public:
    void setInfo()
    {
        m_Name = "张三";
        m_Car = "汽车";
        m_Password = 123456;
    }

    void showInfo()
    {
        std::cout << "姓名：" << m_Name << "\n";
        std::cout << "车辆：" << m_Car << "\n";
        std::cout << "密码：" << m_Password << "\n";
    }
};

int main()
{
    Person p1;
    p1.setInfo();

    p1.m_Name = "李四";
    // p1.m_Car = "自行车";
    // p1.m_Password = 654321;

    p1.showInfo();

    return 0;
}