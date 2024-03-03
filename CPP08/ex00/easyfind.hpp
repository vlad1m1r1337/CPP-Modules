#ifndef CPPMODULESPROJECT_EASYFIND_HPP
#define CPPMODULESPROJECT_EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return it;
}

#endif
