#include <iostream>
#include <string>

class Building
{
    friend class GoodFriend;

private:
    std::string m_Bedroom;

public:
    std::string m_LivingRoom;

    Building() : m_Bedroom("卧室"), m_LivingRoom("客厅")
    {
    }
};

class GoodFriend
{
public:
    void visit(Building &building)
    {
        std::cout << "正在访问：" << building.m_LivingRoom << "\n";
        std::cout << "正在访问：" << building.m_Bedroom << "\n";
    }
};

int main()
{
    Building building;
    GoodFriend friend1;
    friend1.visit(building);

    return 0;
}
