#ifndef POINT_HPP
#define POINT_HPP

class Triangle;

class Point
{
public:
    double x, y;
    
    Point();
    Point(double, double);
    ~Point();

    void print() const;
    double distance_to_point(const Point&);
    bool is_inside_triangle(const Triangle&) const;
};

#endif