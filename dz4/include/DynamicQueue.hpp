#ifndef DYNAMICQUEUE_HPP
#define DYNAMICQUEUE_HPP

#include "CSLL.hpp"

class DynamicQueue
{
protected:
    CSLL container;
public:
    DynamicQueue();
    DynamicQueue(const DynamicQueue& q);
    ~DynamicQueue();

    bool empty() const;
    void enqueue(double);
    double dequeue();

    void print();
};



#endif
