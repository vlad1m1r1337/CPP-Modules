#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	(void)src;
	return *this;
}

void PmergeMe::parseArgs(int ac, char **av) {
	(void)ac;
	(void)av;
	av++;
	while(*av) {
		if (strchr(*av, '-')) {
			throw(std::exception());
		}
		while(**av) {
			if (!isdigit(**av)) {
				throw(std::exception());
			}
			(*av)++;
		}
		av++;
	}
}