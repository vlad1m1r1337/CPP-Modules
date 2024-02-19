#include "ScalarConverter.hpp"
#include "Error.hpp"

void	test(int argc, char **argv) {
	(void)argc;
	(void)argv;
	char c = 'a';
	cout <<"char " << c << endl;
	cout <<"int " << static_cast<int>(c) << endl;
	cout <<"float " << static_cast<float>(c) << endl;
	cout <<"double " << static_cast<double >(c) << endl;
}

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
