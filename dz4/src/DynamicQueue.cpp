#include "DynamicQueue.hpp"
#include <iostream>

DynamicQueue::DynamicQueue()
{
}

DynamicQueue::DynamicQueue(const DynamicQueue& q) : container{q.container}
{
    
}

DynamicQueue::~DynamicQueue()
{
    while (!empty())
    {
        dequeue();
        std::cout << empty() << std::endl;
    }
    
}

bool DynamicQueue::empty() const
{
    return container.empty();
}
void DynamicQueue::enqueue(double val)
{
    container.prepend(val);
}
double DynamicQueue::dequeue()
{
    return container.remove_from_head();
}

void DynamicQueue::print()
{
    if(empty())
        return;
    std::cout << "In queue:";
    container.print();

    std::cout << std::endl;
}