#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Point.hpp"

class Triangle
{
public:
    Point A, B, C;
    double a, b, c;
    Triangle(const Point&, const Point&, const Point&);
    ~Triangle();

    void print() const;
    int triangle_type();
    bool is_inside_triangle(const Point&) const;
    double triangleCircumference();
};

#endif