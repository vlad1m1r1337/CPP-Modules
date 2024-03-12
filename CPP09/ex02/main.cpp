#include "PmergeMe.hpp"

//int main(int ac, char **av) {
//	(void)ac;
//	(void)av;
//	try {
//		PmergeMe pm;
//		pm.validateArgs(ac, av);
//		pm.parseArgs(ac, av);
//		pm.printPairVector();
//		pm.define_biggest_in_pair();
//		pm.printVector();
//	}
//	catch(const std::exception &e) {
//		cout << "Error" << endl;
//	}
//}

int main() {

	int arr[] = {11, 2, 33, 44};
	std::vector<int> numbers(arr, arr + 4);

//	std::vector<int> resLeft = copyLeft(numbers);
//	std::vector<int> resRight = copyRight(numbers);
//
//
//	printVector(resLeft);
//	cout << endl;
//	printVector(resRight);

	printVector(numbers);
	mergeSort(numbers);
//	printVector(numbers);
	return 0;
}
