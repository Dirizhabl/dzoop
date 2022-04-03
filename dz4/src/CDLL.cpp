#include "CDLL.hpp"
#include <iostream>
#include <algorithm>
#include <vector>


CDLL::CDLL():head{nullptr}, tail{nullptr}
{
}

CDLL::CDLL(const CDLL& c):head{c.head}, tail{c.tail}
{
}

CDLL::~CDLL()
{
    while (head!= nullptr)
    {
        remove_from_head();
    }
    
}

bool CDLL::empty() const 
{
    return (head == nullptr);
}

void CDLL::prepend(double val)
{
    Node *n = new Node{val};
    if (!empty())
    {
        tail->next = n;
        head->prev = n;
        n->next = head;
        n->prev = tail;
        head = n;
        return;
    }
    head = n;
    tail = head;
    n->prev = n;
    n->next = n;
    
}

void CDLL::append(double val)
{
    Node *n = new Node{val};
    if (!empty())
    {
        head->prev = n;
        tail->next = n;
        n->next = head;
        n->prev = tail;
        tail = n;
        return;
    }
    head = n;
    tail = head;
    n->prev = n;
    n->next = n;
    
}

double CDLL::remove_from_head()
{
    double val = head->value;
    if(!empty())
    {
        Node *old_head = head;
        if(head->next == head)
        {
            head = nullptr;
            delete old_head;
            return val;
        }

        head = head->next;
        head->prev = tail;
        tail->next = head;
        
        delete old_head;
    }
    return val;
}

double CDLL::remove_from_tail()
{
    double val = tail->value;
    if(!empty())
    {
        Node *old_tail = tail;
        if(tail->next == tail)
        {
            head = nullptr;
            delete old_tail;
            return val;
        }
        val = old_tail->value;

        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete old_tail;
    }
    return val;
}


void CDLL::print() const
{
    std::cout << "------------------------------------" << std::endl;

    std::cout << "Head at: " << head << "; tail at: " << tail << std::endl;

    std::cout << "------------------------------------" << std::endl;
    
    Node *it = head;
    if (!empty())
    {
        it->print();
        do
        {
            it = it->next;
            it->print();
        }while (it->next != head);
        std::cout << "------------------------------------" << std::endl;
    }
}

void CDLL::sort() const
{
    Node *it = head;
    std::vector<double> vec;
    do
    {  
        vec.push_back(it->value);
        it = it->next;
    }while(it->next!=head);
    
    std::sort(vec.begin(), vec.end());
}