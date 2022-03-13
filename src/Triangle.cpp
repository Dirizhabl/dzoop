#include "Triangle.hpp"
#include <iostream>

Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3):A{p1}, B{p2}, C{p3}
{
    a = C.distance_to_point(B);
    b = A.distance_to_point(C);
    c = B.distance_to_point(A);
}

void Triangle::print() const
{
    std::cout << "Triangle:" << std::endl;
    std::cout << " ";
    A.print();
    std::cout << ", ";
    B.print();
    std::cout << ", ";
    C.print();
    std::cout << '\n';
}

int Triangle::triangle_type()
{
    if(a == b && a == c && b == c)
        return 2;
    if(a != b && a != c && b != c)
        return 3;
    return 1;
}

bool Triangle::is_inside_triangle(const Point &point) const
{
    double s = (A.x - C.x) * (point.y - C.y) - (A.y - C.y) * (point.x - C.x);
    double t = (B.x - A.x) * (point.y - A.y) - (B.y - A.y) * (point.y - A.x);

    if ((s < 0) != (t < 0) && s != 0 && t != 0)
        return false;

    double d = (C.x - B.x) * (point.y - B.y) - (C.y - B.y) * (point.x - B.x);
    return d == 0 || (d < 0) == (s + t <= 0);
}

double Triangle::triangleCircumference()
{
    return a + b + c;
}