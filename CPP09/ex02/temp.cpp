void PmergeMe::d_printPairVector() {
    std::deque<std::pair<int, int> >::iterator it;
    for (it = _v.begin(); it != _v.end(); ++it) {
        std::cout << it->first << " " << it->second << " ";
    }
    cout << endl;
}

void PmergeMe::d_printPairVectorWithoutMinusOne() {
    std::deque<std::pair<int, int> >::iterator it;
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

void PmergeMe::d_printBigestInPairVector() {
    printVector(_biggest_in_pair);
}

void PmergeMe::d_printLowestInPairVector() {
    printVector(_lowest_in_pair);
}

void PmergeMe::d_define_biggest_in_pair() {
    _deque_time_start = clock();
    std::deque<std::pair<int, int> >::iterator it;
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

void PmergeMe::d_parseArgs(int ac, char **av) {
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

void PmergeMe::d_create_sorted_n_2() {
    _sorted_biggest = mergeSort(_biggest_in_pair);
}

int PmergeMe::d_find_pair(int smallest_among_large_ones) {
    std::deque< std::pair<int, int> >::iterator it;
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

void PmergeMe::d_erase_in_lowest_pair(int pair) {
    std::deque<int>::iterator it = std::find(_lowest_in_pair.begin(), _lowest_in_pair.end(), pair);

    int index = std::distance(_lowest_in_pair.begin(), it);
    _lowest_in_pair.erase(_lowest_in_pair.begin() + index);
}

void PmergeMe::d_insert_lowest() {
    int smallest_among_large_ones = _sorted_biggest[0];
    int pair = find_pair(smallest_among_large_ones);
    _sorted_biggest.insert(_sorted_biggest.begin(), pair);
    erase_in_lowest_pair(pair);
}

std::deque<int> PmergeMe::d_fill_sub_group(std::deque<int> v, int *pow_of, int *last) {
    std::deque<int>::iterator it;

    for (int i = 0; i < std::pow(2, *pow_of) - *last; i++) {
        v.insert(v.begin(), _lowest_in_pair[0]);
        _lowest_in_pair.erase(_lowest_in_pair.begin());
        if (_lowest_in_pair.size() == 0) {break;}
    }
    (*last) = static_cast<int>(std::pow(2, *pow_of));
    (*pow_of)++;
    return v;
}

void PmergeMe::d_group_remaining() {
    int pow_of = 1;
    int last = 0;
    std::deque<int> vt;
    _grouped.push_back(vt);
    while (_lowest_in_pair.size()) {
        std::deque<std::deque<int> >::iterator it;
        it = _grouped.begin();
        std::deque<int> sub = fill_sub_group(*it, &pow_of, &last);
        _grouped.push_back(sub);
        it++;
    }
    _grouped.erase(_grouped.begin());
}

int PmergeMe::d_find_place_in_binary_search(int index) {
    return _grouped[0][0] >= _sorted_biggest[index] && _grouped[0][0] <= _sorted_biggest[index + 1];
}

void PmergeMe::d_insert_erase_binary(int *index) {
    _sorted_biggest.insert(_sorted_biggest.begin() + *index, _grouped[0][0]);
    _grouped[0].erase(_grouped[0].begin());
    if (_grouped[0].size() == 0) {
        _grouped.erase(_grouped.begin());
    }
    *index = (_sorted_biggest.size() - 1) / 2;
}

void PmergeMe::d_binary_insertion_sort() {
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
}

void PmergeMe::d_output_result() {
    cout << "Before: ";
    printPairVectorWithoutMinusOne();
    cout << "After: ";
    printVector(_sorted_biggest);
    double time = (double)(clock() - _deque_time_start) / CLOCKS_PER_SEC;
    cout << "Time to process: " << time << " s" << endl;
}
