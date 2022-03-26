#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

class myVector
{
private:
    unsigned int _size, _capacity;
    int *P;
public:
    myVector();
    myVector(const myVector&);
    ~myVector();
    
    void push_back(int&);
    int pop_back();
    
    unsigned int get_size() const;
    unsigned int get_capacity() const;

    void print();

    bool empty() const;
    bool full() const;

    int& at(unsigned int);
    int& front();
    int& back();
    int* begin() const;
    int* end() const;
};

#endif