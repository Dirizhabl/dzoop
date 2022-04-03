#ifndef CSLL_HPP
#define CSLL_HPP

#include "Node.hpp"


class CSLL
{
private:
    Node *head;
public:
    CSLL();
    CSLL(const CSLL& c);
    ~CSLL();

    bool empty() const;

    void prepend(double);
    void append(double);

    double remove_from_head();

    void print() const;
};



#endif