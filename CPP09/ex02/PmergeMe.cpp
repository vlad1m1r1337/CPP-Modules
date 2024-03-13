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

void PmergeMe::printPairVector() {
	std::vector<std::pair<int, int> >::iterator it;
	for (it = _v.begin(); it != _v.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
	}
}

void printVector(std::vector<int> v) {
	std::vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void PmergeMe::printBigestInPairVector() {
	printVector(_biggest_in_pair);
}

void PmergeMe::printLowestInPairVector() {
	printVector(_lowest_in_pair);
}

void PmergeMe::define_biggest_in_pair() {
	std::vector<std::pair<int, int> >::iterator it;
	for(it = _v.begin(); it != _v.end(); ++it) {
		if (it->first > it->second) {
			_biggest_in_pair.push_back(it->first);
			_lowest_in_pair.push_back(it->second);
		}
		else {
			_biggest_in_pair.push_back(it->second);
			_lowest_in_pair.push_back(it->first);
		}
	}
}

void PmergeMe::parseArgs(int ac, char **av) {
	(void)ac;
	(void)av;
	int i = 1;
	while(av[i]) {
		if (av[i] && av[i + 1]) {
			int av1 = atoi(av[i]);
			int av2 = atoi(av[i + 1]);
			_v.push_back(std::make_pair(av1, av2));
		}
		else {
			int last = atoi(av[i]);
			_v.push_back(std::make_pair(last, -1));
			break;
		}
		i += 2;
	}
}

//merge sort

std::vector<int> copyLeft(std::vector<int> vec) {
	int arr[vec.size()];
	size_t i = 0;
	for (; i < vec.size() / 2; ++i) {
		arr[i] = vec[i];
	}

	return std::vector<int>(arr, arr + i);
}

std::vector<int> copyRight(std::vector<int> vec) {
	int arr[vec.size()];
	size_t i = vec.size() / 2;
	for (; i < vec.size(); ++i) {
		arr[i] = vec[i];
	}

	return std::vector<int>(arr + vec.size() / 2, arr + i);
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
	unsigned long leftIn = 0, rightIn = 0;

	std::vector<int> res;

	while (leftIn < left.size() && rightIn < right.size()) {
		if (left[leftIn] < right[rightIn]) {
			res.push_back(left[leftIn++]);
		}
		else {
			res.push_back(right[rightIn++]);
		}
	}

	while (leftIn < left.size()) {
		res.push_back(left[leftIn]);
		leftIn++;
	}

	while (rightIn < right.size()) {
		res.push_back(right[rightIn]);
		rightIn++;
	}
	return res;
}

std::vector<int> mergeSort(std::vector<int> v) {
		if (v.size() <= 1) { return v; }
		std::vector<int> left = copyLeft(v);
		std::vector<int> right = copyRight(v);

		return merge(mergeSort(left), mergeSort(right));
}

void PmergeMe::create_sorted_n_2() {
	_sorted_biggest = mergeSort(_biggest_in_pair);
}

void PmergeMe::insert_lowest() {
	int smallest_among_large_ones = _biggest_in_pair[0];


}
