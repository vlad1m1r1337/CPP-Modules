#ifndef CPPMODULESPROJECT_WHATEVER_HPP
#define CPPMODULESPROJECT_WHATEVER_HPP

#include "iostream"

template<typename T, typename Func>
void iter(T& arr, unsigned int length, Func f) {
    for (unsigned int i = 0; i < length; ++i) {
        f(arr[i]);
    }
}

#endif
