#include <iostream>

class AbstractDrinking
{
public:
    virtual void boil() = 0;
    virtual void brew() = 0;
    virtual void pourIntoCup() = 0;
    virtual void addIngredients() = 0;

    void makeDrink()
    {
        boil();
        brew();
        pourIntoCup();
        addIngredients();
    }

    virtual ~AbstractDrinking()
    {
    }
};

class Coffee : public AbstractDrinking
{
public:
    void boil() override
    {
        std::cout << "煮水\n";
    }

    void brew() override
    {
        std::cout << "冲泡咖啡\n";
    }

    void pourIntoCup() override
    {
        std::cout << "倒入咖啡杯\n";
    }

    void addIngredients() override
    {
        std::cout << "加入糖和牛奶\n";
    }
};

class Tea : public AbstractDrinking
{
public:
    void boil() override
    {
        std::cout << "煮水\n";
    }

    void brew() override
    {
        std::cout << "冲泡茶叶\n";
    }

    void pourIntoCup() override
    {
        std::cout << "倒入茶杯\n";
    }

    void addIngredients() override
    {
        std::cout << "加入柠檬\n";
    }
};

int main()
{
    Coffee coffee;
    Tea tea;

    coffee.makeDrink();
    std::cout << "\n";
    tea.makeDrink();

    return 0;
}
