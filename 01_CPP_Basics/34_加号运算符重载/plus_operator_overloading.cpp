#include <iostream>

class Point
{
public:
    int m_X;
    int m_Y;

    Point(int x, int y) : m_X(x), m_Y(y)
    {
    }

    Point operator+(const Point &point)
    {
        return Point(m_X + point.m_X, m_Y + point.m_Y);
    }
};

int main()
{
    Point p1(10, 20);
    Point p2(30, 40);
    Point p3 = p1 + p2;

    std::cout << "结果：(" << p3.m_X << ", " << p3.m_Y << ")\n";

    return 0;
}
