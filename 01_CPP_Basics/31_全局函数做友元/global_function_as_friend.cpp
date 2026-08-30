#include <iostream>
#include <string>

class Building
{
    friend void visit(Building &building);

private:
    std::string m_Bedroom;

public:
    std::string m_LivingRoom;

    Building() : m_Bedroom("卧室"), m_LivingRoom("客厅")
    {
    }
};

void visit(Building &building)
{
    std::cout << "正在访问：" << building.m_LivingRoom << "\n";
    std::cout << "正在访问：" << building.m_Bedroom << "\n";
}

int main()
{
    Building building;
    visit(building);

    return 0;
}
