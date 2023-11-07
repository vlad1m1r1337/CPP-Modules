//#include "iomanip"
//#include "iostream"
//#include "fstream"
//
//std::string reader(char *s) {
//	std::string str(s);
//	std::ifstream in;
//	in.open(str);
//
//}
//
//int main(int argc, char **argv) {
//	if (argc != 4)
//	{
//		std::cout << "Wrong arguments" << std::endl;
//		return 1;
//	}
//	std::string content = reader(argv[1]);
//	return 0;
//}
//
////#include <iostream>
////#include <fstream>
////#include <string>
////
////std::string reader(char *s) {
////	std::string str(s);
////	return str;
////}
////


#include <iostream>
#include <fstream>
#include <string>

std::string reader(char *s) {
	std::string str(s);
	std::string line;
	std::string content;
	std::ifstream in(str);
	if (in.is_open())
	{
		while (std::getline(in, line))
			content += line + "\n";
	}
	in.close();
	return content;
}

void writer(std::string content, char *file, char *substring, char *string) {
	(void)content;
	std::string out_file(file);
	std::string substr(substring);
	std::string str(string);
	std::ofstream out(out_file + ".replace");
	bool found = string.find(substring) != std::string::npos;

}

int main(int argc, char **argv) {
	(void)argc;
	std::string content;
	content = reader(argv[1]);
	std::cout << content << std::endl;
	writer(content, argv[1]);
	return 0;
}
