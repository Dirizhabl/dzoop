#ifndef DYNAMICSTACK_HPP
#define DYNAMICSTACK_HPP

#include <vector>

class DynamicStack
{
private:
    std::vector<int> container;
public:
    DynamicStack();
    DynamicStack(const DynamicStack& S);
    bool empty() const;
    void push(int);
    int pop();
    void print();
    ~DynamicStack();
};

#endif