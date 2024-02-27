#ifndef CPPMODULESPROJECT_MUTANTSTACK_HPP
#define CPPMODULESPROJECT_MUTANTSTACK_HPP

#include "vector"
#include <iostream>
#include <stack>


using std::endl;
using std::cout;

template<class T>
class MutantStack : public std::stack<T> {
	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack<T> &copy) {
		*this = copy;
	}
	MutantStack& operator=(const MutantStack<T> &other) {
		*this = other;
	}

};

#endif
