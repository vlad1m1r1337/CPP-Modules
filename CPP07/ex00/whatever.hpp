#ifndef CPPMODULESPROJECT_WHATEVER_HPP
#define CPPMODULESPROJECT_WHATEVER_HPP

#include "iostream"


template<typename T> void swap(T&, T&);

template<typename T> void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
};

template<typename T> T* max(T*, T*);

template<typename T> T* max(T* a, T* b)
{
    return *a > *b? a : b;
}

#endif
