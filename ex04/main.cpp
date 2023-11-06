//#include "iomanip"
//#include "iostream"
//
//int main(int argc, char **argv) {
//	if (argv[0])
//		;
//	std::string str;
//
//	if (argc != 4)
//	{
//		std::cout << "Wrong arguments" << std::endl;
//		return 1;
//	}
//
//}

#include <iostream>

#include <fstream>

#include <string>

int main() {

	std::ifstream infile("example.txt");

	if (infile.is_open()) {

		std::string str;

		while (std::getline(infile, str)) {
			std::cout << str << std::endl;
		}

	}
	return 0;
}
