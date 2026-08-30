#include <iostream>

class Cube
{
private:
    double m_Length;
    double m_Width;
    double m_Height;

public:
    void setSize(double length, double width, double height)
    {
        m_Length = length;
        m_Width = width;
        m_Height = height;
    }

    double getArea()
    {
        return 2 * (m_Length * m_Width + m_Length * m_Height + m_Width * m_Height);
    }

    double getVolume()
    {
        return m_Length * m_Width * m_Height;
    }

    bool isSameAs(Cube cube)
    {
        return m_Length == cube.m_Length &&
               m_Width == cube.m_Width &&
               m_Height == cube.m_Height;
    }
};

int main()
{
    Cube c1;
    c1.setSize(10, 10, 10);

    Cube c2;
    c2.setSize(10, 10, 10);

    std::cout << "表面积：" << c1.getArea() << "\n";
    std::cout << "体积：" << c1.getVolume() << "\n";
    std::cout << "两个立方体是否相同：" << (c1.isSameAs(c2) ? "是" : "否") << "\n";

    return 0;
}
