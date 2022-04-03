#include "CSLL.hpp"
#include <iostream>

CSLL::CSLL(): head{nullptr}
{
}

CSLL::CSLL(const CSLL& c): head{nullptr}
{
    Node *it = c.head;
    do
    {
        append(it->value);
        it = it -> next;
    } while (it != c.head);
    
}

CSLL::~CSLL()
{
    while(!empty())
        remove_from_head();
}

bool CSLL::empty() const 
{
    return head == nullptr;
}

void CSLL::prepend (double val)
{
    Node* n = new Node{val};

    if(!empty())
    {
        Node *it = head;

        while (it->next != head)
            it = it->next;
        
        n->next = head;
        it->next = n;
        head = n;

        return; 
    }

    head = n;
    n->next = n;
}

void CSLL::append(double val)
{
    prepend(val);
    head = head->next;
}

void CSLL::print() const
{
    if (empty())
        return;

    Node *it = head;
    
    while (it->next != head)
    {
        std::cout << it->value << " ";
        it = it->next;
    }
}

double CSLL::remove_from_head()
{
    Node *it = head;
    double temp = head->value;
    head = head->next;
    delete it;
    
    return temp;
}