#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	(void)argv;
	if (argc != 2) {
		cout << "Wrong prompt" << endl;
		return 1;
	}
	string name = argv[1];
	ScalarConverter::convert(name);
	return 0;
}
