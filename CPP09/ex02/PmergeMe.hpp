#ifndef CPPMODULESPROJECT_PMERGEME_HPP
#define CPPMODULESPROJECT_PMERGEME_HPP

#include "iostream"
#include <cstring>
#include <cstdlib>
#include "exception"
#include "vector"
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

class PmergeMe {
private:
	std::vector<std::pair<int, int > > _v;
	std::vector<int> _biggest_in_pair;
	std::vector<int> _lowest_in_pair;
	std::vector<int> _sorted_biggest;
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	void validateArgs(int ac, char **av);
	void parseArgs(int ac, char **av);
	void printPairVector();
	void define_biggest_in_pair();
	void printBigestInPairVector();
	void printLowestInPairVector();

	void create_sorted_n_2();
    void erase_in_lowest_pair(int pair);
	void insert_lowest();
    int find_pair(int smallest_among_large_ones);

	//merge sort
};

	std::vector<int> copyLeft(std::vector<int> vec);
	std::vector<int> copyRight(std::vector<int> vec);
	std::vector<int> mergeSort(std::vector<int> v);
	void printVector(std::vector<int> v);

#endif
