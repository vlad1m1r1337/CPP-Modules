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

void PmergeMe::validateArgs(int ac, char **av) {
	(void)ac;

	for (int i = 1; i < ac; ++i) {
		char* current_arg = av[i];
		if (strchr(current_arg, '-')) {
			throw(std::exception());
		}
		for (int j = 0; current_arg[j] != '\0'; ++j) {
			if (!isdigit(current_arg[j])) {
				throw(std::exception());
			}
		}
	}
}

void PmergeMe::parseArgs(int ac, char **av) {
	(void)ac;
	(void)av;
	int i = 1;
//	while(av[i]) {
//		cout << "<" << string(av[i]) << ">" << endl;
//		i++;
//	}
//	exit(0);
	while(av[i]) {
		cout << "<" << av[i] << ">" << endl;
		if (av[i] && av[i + 1]) {
			unsigned av1 = stoul(std::string(av[i]));
			unsigned av2 = stoul(std::string(av[i + 1]));
			_v.push_back(std::make_pair(av1, av2));
			i++;
		}
		_v.push_back(std::make_pair(std::stoul(*av), -1));
		i += 2;
	}
}