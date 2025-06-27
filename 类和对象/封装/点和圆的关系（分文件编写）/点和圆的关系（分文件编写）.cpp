#include <iostream>
#include <cmath>
#include "Circle.h"
#include"Point.h"
using namespace std;


int relation(Point& p, Circle& c)
{
    double judge = sqrt((p.x - c.center.x) * (p.x - c.center.x) + (p.y - c.center.y) * (p.y - c.center.y));
    if (judge > c.radius)
    {
        return 0;
    }
    else if (judge < c.radius)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
int main()
{
    Point p;
    p.x = 1;
    p.y = 1;

    Circle c;
    c.center.x = 0;
    c.center.y = 0;
    c.radius = 2;

    int re = relation(p, c);
    switch (re)
    {
    case 0:
        cout << "点在圆外" << endl;
        break;
    case 1:
        cout << "点在圆内" << endl;
        break;
    case 2:
        cout << "点在圆上" << endl;
        break;
    default:break;

    }
    system("pause");
    return 0;

}