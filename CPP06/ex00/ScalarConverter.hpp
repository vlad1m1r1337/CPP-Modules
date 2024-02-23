#ifndef CPPMODULESPROJECT_SCALARCONVERTER_HPP
#define CPPMODULESPROJECT_SCALARCONVERTER_HPP

#include "iostream"
#include <sstream>
#include <stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;
	enum Types {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
	};

class ScalarConverter {
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter &operator=(ScalarConverter const &other);
public:
	static void convert(const string& param);
};
	void literals_check(const string param);
	void main_casting(const string param);
	int	int_check (const char *str);
	int symbol_check(string param);

	//CHAR
	int is_char(string param);

	//INT
	int is_int(string param);

	//DOUBLE
	int is_double(string param);

	//FLOAT
	int is_float(string param);

#endif
