#include "ScalarConverter.hpp"
#include "Error.hpp"

void literals_check(const string param) {
	if (param == "nan") {
		cout << "char: impossible\n"
				"int: impossible\n"
				"float: nanf\n"
				"double: nan"
				<< endl;
		exit(0);
	}
	else if (param == "0") {
		cout << "char: Non displayable\n"
				"int: 0\n"
				"float: 0.0f\n"
				"double: 0.0"
				<< endl;
		exit(0);
	}
	else if (param == "-inff" || param == "-inf") {
		cout << "char: impossible\n"
				"int: impossible\n"
				"float: -inff\n"
				"double: -inf"
				<< endl;
		exit(0);
	}
	else if (param == "+inff" || param == "+inf") {
		cout << "char: impossible\n"
				"int: impossible\n"
				"float: +inff\n"
				"double: +inf"
			 << endl;
		exit(0);
	}
}

int define_types(string param) {
	if (is_char(param)) {return CHAR;}
	else if (is_int(param)) {return INT;}
	else if (is_double(param)) {return DOUBLE;}
	else if (is_float(param)) {return FLOAT;}
	else {return -1;}

}



void ScalarConverter::convert(string param)
{
	int type;
	literals_check(param);
	type = define_types(param);
	if (type == -1) {
		throw Error();
	}
	cout << "type " << type << endl;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return *this;
}
