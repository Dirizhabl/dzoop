#ifndef CDLL_HPP
#define CDLL_HPP
#include "Node.hpp"

class CDLL
{
protected:
    Node *head;
    Node *tail;
public:
    CDLL();
    CDLL(const CDLL& c);
    ~CDLL();

    bool empty() const;
    void prepend(double);
    void append(double);
    double remove_from_head();
    double remove_from_tail();

    void print() const;
    void sort() const;
};


#endif