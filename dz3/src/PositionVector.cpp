#include "PositionVector.hpp"
#include <cmath>
#include <iostream>

PositionVector::PositionVector(): x{0}, y{0}
{}

PositionVector::PositionVector(double x, double y): x{x}, y{y}
{}

PositionVector::PositionVector(const PositionVector& pos_vec): x{pos_vec.x}, y{pos_vec.y}
{}

double PositionVector::norm() const
{
    return sqrt(pow(x,2) + pow(y,2));
}
void PositionVector::print() const
{
    std::cout << "x: " << x << ", y: " << y << ", norm: " << norm() << std::endl;
}

bool operator<(const PositionVector& fst, const PositionVector& snd)
{
    return fst.norm() < snd.norm();
}

bool operator>(const PositionVector& fst, const PositionVector& snd)
{
    return fst.norm() > snd.norm();
}