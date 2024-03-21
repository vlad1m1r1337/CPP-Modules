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
			pm.insert_lowest();
			pm.group_remaining();
			pm.binary_insertion_sort();

            pm.d_parseArgs(ac, av);
            pm.d_define_biggest_in_pair();
            pm.d_create_sorted_n_2();
            pm.d_insert_lowest();
            pm.d_group_remaining();
            pm.d_binary_insertion_sort();
            pm.d_output_result();
		}
	catch(const std::exception &e) {
		cout << "Error" << endl;
	}
}