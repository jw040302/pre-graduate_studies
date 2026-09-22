#include <iostream>
#include <string>

class Teacher
{
public:
    std::string m_Course;
};

class Researcher
{
public:
    std::string m_Project;
};

class Professor : public Teacher, public Researcher
{
};

class Animal
{
public:
    int m_Age;
};

class Sheep : virtual public Animal
{
};

class Camel : virtual public Animal
{
};

class Alpaca : public Sheep, public Camel
{
};

int main()
{
    Professor professor;
    professor.m_Course = "C++程序设计";
    professor.m_Project = "机器人研究";

    std::cout << professor.m_Course << "，" << professor.m_Project << "\n";

    Alpaca alpaca;
    alpaca.m_Age = 3;

    std::cout << "羊驼年龄：" << alpaca.m_Age << "\n";

    return 0;
}
