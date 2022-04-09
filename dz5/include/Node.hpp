#ifndef NODE_HPP
#define NODE_HPP

class Node
{
public:
    int n;
    Node *next;
    Node();
    Node(int , Node *);
    ~Node();
};




#endif