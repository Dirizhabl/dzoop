#include "DynamicStack.hpp"
#include <iostream>



DynamicStack::DynamicStack(/* args */)
{
}

DynamicStack::DynamicStack(const DynamicStack &S): container{S.container}
{
}

DynamicStack::~DynamicStack()
{
}

bool DynamicStack::empty() const
{
    return container.empty();
}

void DynamicStack::push(int x)
{
    container.push_back(x);
}

int DynamicStack::pop()
{
    int back = container.back();
    container.pop_back();
    return back;
}

void DynamicStack::print()
{
    size_t size = container.size();
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}
