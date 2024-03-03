#ifndef CPPMODULESPROJECT_MUTANTSTACK_HPP
#define CPPMODULESPROJECT_MUTANTSTACK_HPP

#include <vector>
#include <iostream>
#include <stack>



using std::endl;
using std::cout;

template<class T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type container_type;
    typedef typename container_type::iterator iterator;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename container_type::reverse_iterator reverse_iterator;
    typedef typename container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }

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
