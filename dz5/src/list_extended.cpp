#include "list_extended.hpp"

double sum(std::list<double> &ld)
{
    double sum = 0.0;
    for (auto &i : ld)
    {
        sum += i;
    }
    return sum;
}

double prod(std::list<double> &ld)
{
    double prod = 1.0;
    for (auto &&i : ld)
    {
        prod *= i;
    }
    return prod;
}

double min(std::list<double> &ld)
{
    double min = __DBL_MAX__;

    for (auto &&i : ld)
    {
        if(min>i)
        min = i;
    }
    return min;
}

double max(std::list<double> &ld)
{
    double max = __DBL_MIN__;

    for (auto &&i : ld)
    {
        if(max<i)
        max = i;
    }
    return max;
}