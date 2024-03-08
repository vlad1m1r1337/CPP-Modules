#ifndef CPPMODULESPROJECT_PMERGEME_HPP
#define CPPMODULESPROJECT_PMERGEME_HPP

#include "iostream"
#include "exception"
#include "vector"

using std::cout;
using std::endl;
using std::string;

class PmergeMe {
private:
	std::vector<unsigned > _v;
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	void parseArgs(int ac, char **av);
};

#endif
