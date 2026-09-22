#include <iostream>
#include <string>

class Animal
{
public:
    virtual void speak() const = 0;
    virtual ~Animal() = 0;
};

Animal::~Animal()
{
    std::cout << "Animal析构函数\n";
}

class Cat : public Animal
{
private:
    std::string *m_Name;

public:
    Cat(std::string name)
    {
        m_Name = new std::string(name);
    }

    void speak() const override
    {
        std::cout << *m_Name << "正在喵喵叫\n";
    }

    ~Cat() override
    {
        delete m_Name;
        m_Name = nullptr;
        std::cout << "Cat析构函数\n";
    }
};

int main()
{
    Animal *animal = new Cat("小白");
    animal->speak();
    delete animal;

    return 0;
}
