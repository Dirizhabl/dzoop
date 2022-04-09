#ifndef LIST_HPP
#define LIST_HPP

#include "Node.hpp"

class list
{
private:
    Node *head{};
public:
    list();

    void push_front(int);
    void display();
    void reverse();

    double avg();
    Node* max();
    Node* min();
    void delete_below_avg();

    bool erase(int);

    ~list();
};

#endif