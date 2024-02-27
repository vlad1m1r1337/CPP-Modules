#include "easyfind.hpp"

int main()
{
	int arr[] = {11, 2, 33, 44, 55};
	std::vector<int> numbers(arr, arr + 5);

	for (unsigned long i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	cout << std::endl;

	try {
		std::vector<int>::iterator it = easyfind(numbers, 11);
		std::cout << "Value found " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(numbers, 33);
		std::cout << "Value found " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(numbers, 55);
		std::cout << "Value found " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(numbers, -1);
		std::cout << "Value found " << *it << std::endl;
	} catch (std::exception &e) {
		std::cout << "Value not found" << std::endl;
	}
}
