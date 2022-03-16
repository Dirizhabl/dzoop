#ifndef MVECTOR_HPP
#define MVECTOR_HPP

template<typename T>

class mVector
{
private:
    unsigned int _size, _capacity;
    T *P;
public:
    mVector();
    mVector(const mVector&);
    ~mVector();
    
    void push_back(T&);
    T pop_back();
    
    unsigned int get_size() const;
    unsigned int get_capacity() const;

    void print();

    bool empty() const;
    bool full() const;

    T& at(unsigned int);
    T& front();
    T& back();
};

template class mVector<int>;




#endif