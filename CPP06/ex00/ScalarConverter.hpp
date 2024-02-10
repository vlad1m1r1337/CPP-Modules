#ifndef CPPMODULESPROJECT_SCALARCONVERTER_HPP
#define CPPMODULESPROJECT_SCALARCONVERTER_HPP

#include "iostream"
#include <sstream>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

using std::string;
using std::cout;
using std::cin;
using std::endl;
//using std::

class ScalarConverter {
public:
	static void convert(const string param);

	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter &operator=(ScalarConverter const &other);
};
	void literals_check(const string param);
	void main_casting(const string param);
	int	int_check (const char *str);


#endif
