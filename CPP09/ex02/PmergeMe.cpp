#include "PmergeMe.hpp"

//merge sort for containers
template<typename Container>
Container copyLeft(Container container) {
    int arr[container.size()];
    size_t i = 0;
    for (; i < container.size() / 2; ++i) {
        arr[i] = container[i];
    }

    return Container(arr, arr + i);
}

template<typename Container>
Container copyRight(Container container) {
    int arr[container.size()];
    size_t i = container.size() / 2;
    for (; i < container.size(); ++i) {
        arr[i] = container[i];
    }

    return Container(arr + container.size() / 2, arr + i);
}

template<typename Container>
Container merge(Container left, Container right) {
    unsigned long leftIn = 0, rightIn = 0;

    Container res;

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

template<typename Container>
Container mergeSort(Container container) {
    if (container.size() <= 1) { return container; }
    Container left = copyLeft(container);
    Container right = copyRight(container);

    return merge(mergeSort(left), mergeSort(right));
}

//not member functions

void printVector(std::vector<int> v) {
    std::vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printVectorVector(std::vector<std::vector<int> > v) {
    std::vector<std::vector<int> >::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        printVector(*it);
        cout << endl;
    }
}

//Ortodoxal Canonical

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	(void)src;
	return *this;
}

// validate

void PmergeMe::validateArgs(int ac, char **av) {
	(void)ac;
    if (ac == 1) {
        throw std::exception();
    }
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

//vector

void PmergeMe::printPairVector() {
	std::vector<std::pair<int, int> >::iterator it;
	for (it = _v.begin(); it != _v.end(); ++it) {
		std::cout << it->first << " " << it->second << " ";
	}
    cout << endl;
}

void PmergeMe::printPairVectorWithoutMinusOne() {
    std::vector<std::pair<int, int> >::iterator it;
    it = _v.begin();
    for (; it != _v.end() - 1; ++it) {
        std::cout << it->first << " " << it->second << " ";
    }
    cout << it->first;
    if (it->second == -1) {
        cout << endl;
    }
    else {
        cout << " " << it->second << endl;
    }
}

void PmergeMe::printBigestInPairVector() {
	printVector(_biggest_in_pair);
}

void PmergeMe::printLowestInPairVector() {
	printVector(_lowest_in_pair);
}

void PmergeMe::define_biggest_in_pair() {
    _vector_time_start = clock();
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

void PmergeMe::create_sorted_n_2() {
	_sorted_biggest = mergeSort(_biggest_in_pair);
}

int PmergeMe::find_pair(int smallest_among_large_ones) {
    std::vector< std::pair<int, int> >::iterator it;
    for (it = _v.begin(); it < _v.end(); it++) {
        if (it->first == smallest_among_large_ones && it->first > it->second) {
            return it->second;
        }
        else if (it->second == smallest_among_large_ones && it->second > it->first) {
            return it->first;
        }
    }
    return 0;
}

void PmergeMe::erase_in_lowest_pair(int pair) {
    std::vector<int>::iterator it = std::find(_lowest_in_pair.begin(), _lowest_in_pair.end(), pair);

    int index = std::distance(_lowest_in_pair.begin(), it);
    _lowest_in_pair.erase(_lowest_in_pair.begin() + index);
}

void PmergeMe::insert_lowest() {
	int smallest_among_large_ones = _sorted_biggest[0];
    int pair = find_pair(smallest_among_large_ones);
    _sorted_biggest.insert(_sorted_biggest.begin(), pair);
    erase_in_lowest_pair(pair);
}

std::vector<int> PmergeMe::fill_sub_group(std::vector<int> v, int *pow_of, int *last) {
	std::vector<int>::iterator it;

	for (int i = 0; i < std::pow(2, *pow_of) - *last; i++) {
		v.insert(v.begin(), _lowest_in_pair[0]);
		_lowest_in_pair.erase(_lowest_in_pair.begin());
		if (_lowest_in_pair.size() == 0) {break;}
	}
	(*last) = static_cast<int>(std::pow(2, *pow_of));
	(*pow_of)++;
	return v;
}

void PmergeMe::group_remaining() {
	int pow_of = 1;
	int last = 0;
	std::vector<int> vt;
	_grouped.push_back(vt);
	while (_lowest_in_pair.size()) {
		std::vector<std::vector<int> >::iterator it;
		it = _grouped.begin();
		std::vector<int> sub = fill_sub_group(*it, &pow_of, &last);
		_grouped.push_back(sub);
		it++;
	}
	_grouped.erase(_grouped.begin());
}

int PmergeMe::find_place_in_binary_search(int index) {
	return _grouped[0][0] >= _sorted_biggest[index] && _grouped[0][0] <= _sorted_biggest[index + 1];
}

void PmergeMe::insert_erase_binary(int *index) {
	_sorted_biggest.insert(_sorted_biggest.begin() + *index, _grouped[0][0]);
	_grouped[0].erase(_grouped[0].begin());
	if (_grouped[0].size() == 0) {
		_grouped.erase(_grouped.begin());
	}
	*index = (_sorted_biggest.size() - 1) / 2;
}

void PmergeMe::binary_insertion_sort() {
	int index = (_sorted_biggest.size() - 1) / 2;
	while(!_grouped.empty()) {
		if (find_place_in_binary_search(index)) {
			insert_erase_binary(&++index);
		}
		if (_grouped[0][0] > _sorted_biggest[index]) {
            index++;
			if (static_cast<long unsigned int>(index + 1) == _sorted_biggest.size()) {
				insert_erase_binary(&index);
			}
		}
		else if (_grouped[0][0] < _sorted_biggest[index]) {
			index--;
			if (index == -1) {
                index++;
				insert_erase_binary(&index);
			}
		}
	}
    if (_sorted_biggest[0] == -1) {
        _sorted_biggest.erase(_sorted_biggest.begin());
    }
    _v_duration = (std::clock() - _vector_time_start)/(double)CLOCKS_PER_SEC;
}


//deque

void PmergeMe::d_printPairVector() {
    std::deque<std::pair<int, int> >::iterator it;
    for (it = _d.begin(); it != _d.end(); ++it) {
        std::cout << it->first << " " << it->second << " ";
    }
    cout << endl;
}

void PmergeMe::d_printPairVectorWithoutMinusOne() {
    std::deque<std::pair<int, int> >::iterator it;
    it = _d.begin();
    for (; it != _d.end() - 1; ++it) {
        std::cout << it->first << " " << it->second << " ";
    }
    cout << it->first;
    if (it->second == -1) {
        cout << endl;
    }
    else {
        cout << " " << it->second << endl;
    }
}

void PmergeMe::d_printBigestInPairVector() {
    printVector(_biggest_in_pair);
}

void PmergeMe::d_printLowestInPairVector() {
    printVector(_lowest_in_pair);
}

void PmergeMe::d_define_biggest_in_pair() {
    _deque_time_start = clock();
    std::deque<std::pair<int, int> >::iterator it;
    for(it = _d.begin(); it != _d.end(); ++it) {
        if (it->first > it->second) {
            _d_biggest_in_pair.push_back(it->first);
            _d_lowest_in_pair.push_back(it->second);
        }
        else {
            _d_biggest_in_pair.push_back(it->second);
            _d_lowest_in_pair.push_back(it->first);
        }
    }
}

void PmergeMe::d_parseArgs(int ac, char **av) {
    (void)ac;
    (void)av;
    int i = 1;
    while(av[i]) {
        if (av[i] && av[i + 1]) {
            int av1 = atoi(av[i]);
            int av2 = atoi(av[i + 1]);
            _d.push_back(std::make_pair(av1, av2));
        }
        else {
            int last = atoi(av[i]);
            _d.push_back(std::make_pair(last, -1));
            break;
        }
        i += 2;
    }
}

void PmergeMe::d_create_sorted_n_2() {
    _d_sorted_biggest = mergeSort(_d_biggest_in_pair);
}

int PmergeMe::d_find_pair(int smallest_among_large_ones) {
    std::deque< std::pair<int, int> >::iterator it;
    for (it = _d.begin(); it < _d.end(); it++) {
        if (it->first == smallest_among_large_ones && it->first > it->second) {
            return it->second;
        }
        else if (it->second == smallest_among_large_ones && it->second > it->first) {
            return it->first;
        }
    }
    return 0;
}

void PmergeMe::d_erase_in_lowest_pair(int pair) {
    std::deque<int>::iterator it = std::find(_d_lowest_in_pair.begin(), _d_lowest_in_pair.end(), pair);

    if (it != _d_lowest_in_pair.end()) {
        size_t index = it - _d_lowest_in_pair.begin();
        _d_lowest_in_pair.erase(_d_lowest_in_pair.begin() + index);
    }
}

void PmergeMe::d_insert_lowest() {
    int smallest_among_large_ones = _d_sorted_biggest[0];
    int pair = find_pair(smallest_among_large_ones);
    _d_sorted_biggest.insert(_d_sorted_biggest.begin(), pair);
    erase_in_lowest_pair(pair);
}

std::deque<int> PmergeMe::d_fill_sub_group(std::deque<int> v, int *pow_of, int *last) {
    std::deque<int>::iterator it;

    for (int i = 0; i < std::pow(2, *pow_of) - *last; i++) {
        v.insert(v.begin(), _d_lowest_in_pair[0]);
        _d_lowest_in_pair.erase(_d_lowest_in_pair.begin());
        if (_d_lowest_in_pair.size() == 0) {break;}
    }
    (*last) = static_cast<int>(std::pow(2, *pow_of));
    (*pow_of)++;
    return v;
}

void PmergeMe::d_group_remaining() {
    int pow_of = 1;
    int last = 0;
    std::deque<int> vt;
    _d_grouped.push_back(vt);
    while (_d_lowest_in_pair.size()) {
        std::deque<std::deque<int> >::iterator it;
        it = _d_grouped.begin();
        std::deque<int> sub = d_fill_sub_group(*it, &pow_of, &last);
        _d_grouped.push_back(sub);
        it++;
    }
    _d_grouped.erase(_d_grouped.begin());
}

int PmergeMe::d_find_place_in_binary_search(int index) {
    return _d_grouped[0][0] >= _d_sorted_biggest[index] && _d_grouped[0][0] <= _d_sorted_biggest[index + 1];
}

void PmergeMe::d_insert_erase_binary(int *index) {
    _d_sorted_biggest.insert(_d_sorted_biggest.begin() + *index, _d_grouped[0][0]);
    _d_grouped[0].erase(_d_grouped[0].begin());
    if (_d_grouped[0].size() == 0) {
        _d_grouped.erase(_d_grouped.begin());
    }
    *index = (_d_sorted_biggest.size() - 1) / 2;
}

void PmergeMe::d_binary_insertion_sort() {
    int index = (_d_sorted_biggest.size() - 1) / 2;
    while(!_d_grouped.empty()) {
        if (d_find_place_in_binary_search(index)) {
            d_insert_erase_binary(&++index);
        }
        if (_d_grouped[0][0] > _d_sorted_biggest[index]) {
            index++;
            if (static_cast<long unsigned int>(index + 1) == _d_sorted_biggest.size()) {
                d_insert_erase_binary(&index);
            }
        }
        else if (_d_grouped[0][0] < _d_sorted_biggest[index]) {
            index--;
            if (index == -1) {
                index++;
                d_insert_erase_binary(&index);
            }
        }
    }
    if (_d_sorted_biggest[0] == -1) {
        _d_sorted_biggest.erase(_d_sorted_biggest.begin());
    }
    if (_d_sorted_biggest[0] == -1) {
        _d_sorted_biggest.erase(_d_sorted_biggest.begin());
    }
    _d_duration = (std::clock() - _deque_time_start)/(double)CLOCKS_PER_SEC;
}

void printDeque(std::deque<int> d) {
    std::deque<int>::iterator it;
    for (it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void PmergeMe::printPairDequeWithoutMinusOne() {
    std::deque<std::pair<int, int> >::iterator it;
    it = _d.begin();
    for (; it != _d.end() - 1; ++it) {
        std::cout << it->first << " " << it->second << " ";
    }
    cout << it->first;
    if (it->second == -1) {
        cout << endl;
    }
    else {
        cout << " " << it->second << endl;
    }
}


void PmergeMe::d_output_result() {
    cout << "Before: ";
    printPairDequeWithoutMinusOne();
    cout << "After: ";
    printDeque(_d_sorted_biggest);
    cout << "Time to process with std::vector: " << _v_duration * 1000000 << " us" << endl;
    cout << "Time to process with std::deque: " << _d_duration * 1000000 << " us" << endl;
}

