#include <iostream>

class Animal
{
public:
    virtual void speak() const
    {
        std::cout << "动物正在叫\n";
    }

    virtual ~Animal()
    {
    }
};

class Cat : public Animal
{
public:
    void speak() const override
    {
        std::cout << "小猫正在喵喵叫\n";
    }
};

class Dog : public Animal
{
public:
    void speak() const override
    {
        std::cout << "小狗正在汪汪叫\n";
    }
};

void makeSound(const Animal &animal)
{
    animal.speak();
}

int main()
{
    Cat cat;
    Dog dog;

    makeSound(cat);
    makeSound(dog);

    return 0;
}
