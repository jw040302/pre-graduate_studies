#include <iostream>

class CPU
{
public:
    virtual void calculate() const = 0;
    virtual ~CPU()
    {
    }
};

class GraphicsCard
{
public:
    virtual void display() const = 0;
    virtual ~GraphicsCard()
    {
    }
};

class Memory
{
public:
    virtual void store() const = 0;
    virtual ~Memory()
    {
    }
};

class IntelCPU : public CPU
{
public:
    void calculate() const override
    {
        std::cout << "Intel CPU正在计算\n";
    }
};

class NvidiaGraphicsCard : public GraphicsCard
{
public:
    void display() const override
    {
        std::cout << "NVIDIA显卡正在显示画面\n";
    }
};

class KingstonMemory : public Memory
{
public:
    void store() const override
    {
        std::cout << "金士顿内存正在存储数据\n";
    }
};

class Computer
{
private:
    CPU *m_CPU;
    GraphicsCard *m_GraphicsCard;
    Memory *m_Memory;

public:
    Computer(CPU *cpu, GraphicsCard *graphicsCard, Memory *memory)
        : m_CPU(cpu), m_GraphicsCard(graphicsCard), m_Memory(memory)
    {
    }

    void work() const
    {
        m_CPU->calculate();
        m_GraphicsCard->display();
        m_Memory->store();
    }

    ~Computer()
    {
        delete m_CPU;
        delete m_GraphicsCard;
        delete m_Memory;
    }
};

int main()
{
    Computer computer(new IntelCPU, new NvidiaGraphicsCard, new KingstonMemory);
    computer.work();

    return 0;
}
