#include "Node.hpp"
#include <iostream>


Node::Node():prev{nullptr}, next{nullptr}, value{}
{}

Node::Node(double val):prev{nullptr}, next{nullptr}, value{val}
{

}

Node::Node(const Node& n): prev{n.prev}, next{n.next}, value{n.value}
{}
Node::~Node()
{
    std::cout << "Delete node at: " << this << std::endl;
}

//mozda treba treba cijeli node premjestiti zajedno sa pointerima??
void Node::swap(Node& n)
{
    double val = n.value;
    n.value = value;
    value = val;
}

void Node::print() const
{
    std::cout << "Node at: " << this;
    if (prev != nullptr)
        std::cout << "; prev at: " << prev;
    
    if(next != nullptr)
        std::cout << "; next at: " << next;
    
    std::cout << "; value: " << value << std::endl; 
}
