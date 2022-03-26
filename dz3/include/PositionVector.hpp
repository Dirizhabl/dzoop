#ifndef POSITIONVECTOR_HPP
#define POSITIONVECTOR_HPP

struct PositionVector
{
    double x, y;

    PositionVector();
    PositionVector(double, double);
    PositionVector(const PositionVector&);
    
    friend bool operator<(const PositionVector&, const PositionVector&);
    double norm() const;
    void print() const;
};


#endif