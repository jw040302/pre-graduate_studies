#include <iostream>

class Person
{
private:
    int age;

public:
    Person &setAge(int age)
    {
        this->age = age;
        return *this;
    }

    int getAge()
    {
        return this->age;
    }
};

int main()
{
    Person p1;
    p1.setAge(20).setAge(25);

    std::cout << "年龄：" << p1.getAge() << "\n";

    return 0;
}
