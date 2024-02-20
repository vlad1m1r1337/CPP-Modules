#include "ScalarConverter.hpp"
#include "Error.hpp"

int main(int argc, char **argv) {
	try {
		if (argc != 2) {
			throw Error();
		}
		string name = argv[1];
		ScalarConverter::convert(name);
	}
	catch (const Error &e) {
		cout << e.what() << endl;
	}
	return 0;
}
