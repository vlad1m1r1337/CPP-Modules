#ifndef CPPMODULESPROJECT_PMERGEME_HPP
#define CPPMODULESPROJECT_PMERGEME_HPP

#include "iostream"
#include <cstring>
#include <cstdlib>
#include "exception"
#include "vector"
#include "deque"
#include <algorithm>
#include <cmath>
#include "ctime"

using std::cout;
using std::endl;
using std::string;

class PmergeMe {
private:
	std::vector<std::pair<int, int > > _v;
	std::vector<int> _biggest_in_pair;
	std::vector<int> _lowest_in_pair;
	std::vector<int> _sorted_biggest;
	std::vector<std::vector<int> > _grouped;

    clock_t _vector_time_start;
    double _v_duration;

    std::deque<std::pair<int, int > > _d;
    std::deque<int> _d_biggest_in_pair;
    std::deque<int> _d_lowest_in_pair;
    std::deque<int> _d_sorted_biggest;
    std::deque<std::deque<int> > _d_grouped;

    clock_t _deque_time_start;
    double _d_duration;
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	void validateArgs(int ac, char **av);

	void parseArgs(int ac, char **av);
	void printPairVector();
    void printPairVectorWithoutMinusOne();
	void define_biggest_in_pair();
	void printBigestInPairVector();
	void printLowestInPairVector();

	void create_sorted_n_2();
    void erase_in_lowest_pair(int pair);
	void insert_lowest();
    int find_pair(int smallest_among_large_ones);

	//
	int find_place_in_binary_search(int index);
	std::vector<int> fill_sub_group(std::vector<int> v, int *pow, int *last);
	void group_remaining();

	// binary insertion sort
	void insert_erase_binary(int *index);
	void binary_insertion_sort();

    //output
    void output_result();

    //deque
    void d_parseArgs(int ac, char **av);
    void d_printPairVector();
    void d_printPairVectorWithoutMinusOne();
    void d_define_biggest_in_pair();
    void d_printBigestInPairVector();
    void d_printLowestInPairVector();

    void d_create_sorted_n_2();
    void d_erase_in_lowest_pair(int pair);
    void d_insert_lowest();
    int d_find_pair(int smallest_among_large_ones);

    void printPairDequeWithoutMinusOne();

    //
    int d_find_place_in_binary_search(int index);
    std::deque<int> d_fill_sub_group(std::deque<int> v, int *pow, int *last);
    void d_group_remaining();

    // binary insertion sort
    void d_insert_erase_binary(int *index);
    void d_binary_insertion_sort();

    //output
    void d_output_result();

};

	//merge sort
	void printVector(std::vector<int> v);
	void printVectorVector(std::vector<std::vector<int> > v);

#endif
