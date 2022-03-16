#include "mVector.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>


template<typename T>
mVector<T>::mVector():P{nullptr}
{
    _capacity = 0;
    _size = 0;
}
template mVector<int>::mVector();

template<typename T>
mVector<T>::mVector(const mVector<T>& vec)
{
    _size = vec.get_size();
    _capacity = vec.get_capacity();
    P = new T[_capacity];
}
template mVector<int>::mVector(const mVector<int>&);

template<typename T>
mVector<T>::~mVector()
{
    delete[] P;
}
template mVector<int>::~mVector();

template<typename T>
void mVector<T>::push_back(T& data)
{
    _size++;
    if(_capacity == 0)
    {
        _capacity = 1;
        P = new T[_capacity];
    }
    else if(_capacity < _size)
    {
        _capacity *= 2;
        P = static_cast<int*>(realloc(P, _capacity*sizeof(T)));;
    }
    
    P[_size-1] = data;
}
template<typename T>
T mVector<T>::pop_back()
{
    _size--;
    unsigned int cap = _capacity*0.5;
    T temp = P[_size];
    if (_size==cap)
    {
        _capacity = cap;
        P = static_cast<T*>(realloc(P, _capacity*sizeof(T)));
        //std::cout << std::endl << _size*sizeof(T) << std::endl;
    }
    
    return temp;
}

template<typename T>
unsigned int mVector<T>::get_size() const
{
    return _size;
}
template<typename T>
unsigned int mVector<T>::get_capacity() const
{
    return _capacity;
}

template<typename T>
void mVector<T>::print()
{
    for (size_t i = 0; i < _size; i++)
    {
        std::cout << P[i] << " ";
    }
    std::cout << std::endl;
    
}

template<typename T>
bool mVector<T>::empty() const
{
    return _size == 0;
}
template<typename T>
bool mVector<T>::full() const
{
    return _capacity == _size;
}

template<typename T>
T& mVector<T>::at(unsigned int n)
{
    return P[n];
}
template<typename T>
T& mVector<T>::front()
{
    return P[0];
}
template<typename T>
T& mVector<T>::back()
{
    return P[_size-1];
}
