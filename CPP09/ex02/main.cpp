#include "PmergeMe.hpp"

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	try {
			PmergeMe pm;
			pm.validateArgs(ac, av);
			pm.parseArgs(ac, av);
			pm.define_biggest_in_pair();
			pm.create_sorted_n_2();
//			pm.insert_lowest();
		}
	catch(const std::exception &e) {
		cout << "Error" << endl;
	}
}
