#ifndef NODE_HPP
#define NODE_HPP

struct Node
{
    Node*prev;
    Node*next;
    double value;
    Node();
    Node(double value);
    Node(const Node &n);
    // prilikom čišćenja ispisujemo adresu
    ~Node();
    //swap premješta sadržaj između dva čvora
    void swap(Node &n);
    // ispisujemo adresu, adresu prethodnog, adresu sljedećeg te vrijednost
    void print() const;
};

#endif