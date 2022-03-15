#include "Point.hpp"
#include "Triangle.hpp"
#include <iostream>
#include <cmath>

Point::Point():x{0.0},y{0.0}{}

Point::Point(double x, double y): x{x}, y{y}{}

Point::~Point(){}

void Point::print() const
{
    std::cout << "(" << x << ", " << y << ")";
}

double Point::distance_to_point(const Point &p)
{
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

bool Point::is_inside_triangle(const Triangle& tri) const
{
    double s = (tri.A.x - tri.C.x) * (y - tri.C.y) - (tri.A.y - tri.C.y) * (x - tri.C.x);
    double t = (tri.B.x - tri.A.x) * (y - tri.A.y) - (tri.B.y - tri.A.y) * (y - tri.A.x);

    if ((s < 0) != (t < 0) && s != 0 && t != 0)
        return false;

    double d = (tri.C.x - tri.B.x) * (y - tri.B.y) - (tri.C.y - tri.B.y) * (x - tri.B.x);
    return d == 0 || (d < 0) == (s + t <= 0);
}