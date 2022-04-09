#include "Node.hpp"

Node::Node() : next{nullptr}
{
}

Node::Node(int n, Node *N): n{n}, next{N}
{
}

Node::~Node()
{
}