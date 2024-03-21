#include "RPN.hpp"

int main(int argc, char** argv) {
	(void)argv;
	try {
		if (argc != 2) {
			throw std::exception();
		}
		RPN rpn;
		rpn.calculate(argv[1]);
		rpn.printResult();
	} catch (const std::exception& e) {
		cout << "Error" << endl;
	}
	return 0;
}
