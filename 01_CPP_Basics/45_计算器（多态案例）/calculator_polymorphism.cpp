#include <iostream>

class Calculator
{
public:
    virtual double getResult(double first, double second) const = 0;

    virtual ~Calculator()
    {
    }
};

class AddCalculator : public Calculator
{
public:
    double getResult(double first, double second) const override
    {
        return first + second;
    }
};

class SubtractCalculator : public Calculator
{
public:
    double getResult(double first, double second) const override
    {
        return first - second;
    }
};

void showResult(const Calculator &calculator, double first, double second)
{
    std::cout << "计算结果：" << calculator.getResult(first, second) << "\n";
}

int main()
{
    AddCalculator add;
    SubtractCalculator subtract;

    showResult(add, 10, 5);
    showResult(subtract, 10, 5);

    return 0;
}
