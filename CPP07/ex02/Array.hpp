#ifndef CPPMODULESPROJECT_ARRAY_HPP
#define CPPMODULESPROJECT_ARRAY_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;
public:
    Array() {
        _array =  new T[0];
    }
    Array(unsigned int n) {
        _array =  new T[n];
        _size = n;
    }
    Array(const Array &other) {
        _array = new T[other._size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
    }
    ~Array() {
        delete[] _array;
    }
    Array &operator=(const Array &other) {
        if (this == &other) {
            return *this;
        }
        delete[] _array;
        _array = new T[other._size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
        return *this;
    }
    T &operator[](unsigned int i) {
        if (i >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _array[i];
    }
    unsigned int size() const {
        return _size;
    }
};

#endif
