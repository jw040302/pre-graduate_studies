#include <iostream>

class Point
{
private:
    double m_X;
    double m_Y;

public:
    void setPosition(double x, double y)
    {
        m_X = x;
        m_Y = y;
    }

    double getX()
    {
        return m_X;
    }

    double getY()
    {
        return m_Y;
    }
};

class Circle
{
private:
    Point m_Center;
    double m_Radius;

public:
    void setCenter(Point center)
    {
        m_Center = center;
    }

    void setRadius(double radius)
    {
        m_Radius = radius;
    }

    int getPointPosition(Point point)
    {
        double xDistance = point.getX() - m_Center.getX();
        double yDistance = point.getY() - m_Center.getY();
        double distanceSquared = xDistance * xDistance + yDistance * yDistance;
        double radiusSquared = m_Radius * m_Radius;

        if (distanceSquared == radiusSquared)
        {
            return 0;
        }

        return distanceSquared < radiusSquared ? -1 : 1;
    }
};

int main()
{
    Point center;
    center.setPosition(0, 0);

    Circle circle;
    circle.setCenter(center);
    circle.setRadius(5);

    Point point;
    point.setPosition(3, 4);

    int position = circle.getPointPosition(point);

    if (position == 0)
    {
        std::cout << "点在圆上\n";
    }
    else if (position < 0)
    {
        std::cout << "点在圆内\n";
    }
    else
    {
        std::cout << "点在圆外\n";
    }

    return 0;
}
