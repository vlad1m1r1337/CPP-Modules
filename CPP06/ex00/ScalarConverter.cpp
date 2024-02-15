#include "ScalarConverter.hpp"

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

void print_char(int intValue) {
	if (intValue > 127) {
		cout << "char: impossible" << endl;
		return ;
	}
	else if (intValue <= 32) {
		cout << "char: Non displayable" << endl;
		return ;
	}
	cout << "some" << endl;
	std::cout << "char: \'" << static_cast<char>(intValue) << "\'" << endl;
}

void print_int(int intValue) {
	std::cout << "int: " << intValue << std::endl;
}

void convert_char_int(const string param) {
	std::istringstream iss(param);
	int intValue;

	if (int_check(param.c_str())) {
		std::cout << "char: impossible\n"
					 "int: impossible"
					 <<  std::endl;
		return;
	}
	if (iss >> intValue) {
		print_char(intValue);
		print_int(intValue);
	}
}

void convert_to_float(const string param) {
	std::istringstream iss_float(param);
	float floatValue;

	if (iss_float >> floatValue) {
		std::cout << "float: " << (floatValue) << "f" << endl;
	} else {
		std::cerr << "Conversion float failed: Invalid input" << std::endl;
	}
}

void convert_to_double(const string param) {
	std::istringstream iss_double(param);
	double doubleValue;

	if (iss_double >> doubleValue) {
		std::cout << "double: " << static_cast<double >(doubleValue) << endl;
	} else {
		std::cerr << "Conversion double failed: Invalid input" << std::endl;
	}
}

void main_casting(const string param) {
	convert_char_int(param);
	convert_to_float(param);
	convert_to_double(param);
}

void ScalarConverter::convert(string param) {

	literals_check(param);
//	if (param[param.length()- 1] == 'f') {
//		param[param.length()- 1] = '\0';
//	}
	main_casting(param);
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
