#include "myVector.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>


myVector::myVector():P{nullptr}
{
    _capacity = 0;
    _size = 0;
}



myVector::myVector(const myVector& vec)
{
    _size = vec.get_size();
    _capacity = vec.get_capacity();
    P = new int[_capacity];
}



myVector::~myVector()
{
    delete[] P;
}



void myVector::push_back(int& data)
{
    _size++;
    if(_capacity == 0)
    {
        _capacity = 1;
        P = new int[_capacity];
    }
    else if(_capacity < _size)
    {
        _capacity *= 2;
        P = static_cast<int*>(realloc(P, _capacity*sizeof(int)));;
    }
    
    P[_size-1] = data;
}

int myVector::pop_back()
{
    _size--;
    unsigned int cap = _capacity*0.5;
    int temp = P[_size];
    if (_size==cap)
    {
        _capacity = cap;
        P = static_cast<int*>(realloc(P, _capacity*sizeof(int)));
        //std::cout << std::endl << _size*sizeof(T) << std::endl;
    }
    
    return temp;
}


unsigned int myVector::get_size() const
{
    return _size;
}

unsigned int myVector::get_capacity() const
{
    return _capacity;
}


void myVector::print()
{
    for (size_t i = 0; i < _size; i++)
    {
        std::cout << P[i] << " ";
    }
    std::cout << std::endl;
    
}


bool myVector::empty() const
{
    return _size == 0;
}

bool myVector::full() const
{
    return _capacity == _size;
}


int& myVector::at(unsigned int n)
{
    return P[n];
}

int& myVector::front()
{
    return P[0];
}

int& myVector::back()
{
    return P[_size-1];
}

int* myVector::begin()const
{
    return P;
}

int* myVector::end()const
{
    return P+_size;
}