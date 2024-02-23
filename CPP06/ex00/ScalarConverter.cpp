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
	if (param == "nanf") {
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

void find_dot_errors(string param) {
	if (param[param.length() - 1] == '.' || param[0] == '.') {
		throw Error();
	}
	int i = -1;
	int k = 0;
	while(param[++i]) {
		if (param[i] == '.') {
			k++;
			if (k > 1) {
				throw Error();
			}
		}
	}
}

int define_types(const string& param) {
	find_dot_errors(param);
	if (is_char(param)) {return CHAR;}
	else if (is_int(param)) {return INT;}
	else if (is_float(param)) {return FLOAT;}
	else if (is_double(param)) {return DOUBLE;}
	else {return -1;}

}

void it_is_char(const string& param) {
	cout << "char: \'" << param << "\'" << endl;
	cout << "int: "<< static_cast<int>(param[0]) << endl;
	cout << "float: "<< static_cast<float>(param[0]) << ".0f" << endl;
	cout << "double: "<< static_cast<double>(param[0]) << ".0" << endl;
}

void it_is_int(const string& param) {
	int num = atoi(param.c_str());

	if (num < 33) {
		cout << "char: Non displayable" << endl;
	}
	else if (num > 126) {
		cout << "char: impossible" << endl;
	}
	else {
		cout << "char: " << static_cast<char>(num) << endl;
	}
	cout << "int: "<< (num) << endl;
	cout << "float: "<< static_cast<float>(num) << ".0f" << endl;
	cout << "double: "<< static_cast<double>(num) << ".0" << endl;
}

void	it_is_float(const string& param) {
	char *temp_param = (char *)param.c_str();
	temp_param[strlen(temp_param - 1)] = '\0';
	double num = atof(temp_param);

	cout << "char: " << "Non displayable" << endl;
	if (num < INT_MIN || num > INT_MAX) {
		cout << "int: impossible" << endl;
	}
	else {
		cout << "int " << static_cast<int>(num) << endl;
	}
	cout << "float: "<< static_cast<float>(num) << "f" << endl;
	cout << "double: "<< static_cast<double>(num) << endl;
}

void	it_is_double(const string& param) {
	double num = atof(param.c_str());

	cout << "char: " << "Non displayable" << endl;
	if (num < INT_MIN || num > INT_MAX) {
		cout << "int: impossible" << endl;
	}
	else {
		cout << "int " << static_cast<int>(num) << endl;
	}
	cout << "float: "<< static_cast<float>(num) << "f" << endl;
	cout << "double: "<< static_cast<double>(num) << endl;
}

void casting(const string& param, int type) {
	switch (type) {
		case CHAR:
			it_is_char(param);
			break;
		case INT:
			it_is_int(param);
			break;
		case FLOAT:
			it_is_float(param);
			break;
		case DOUBLE:
			it_is_double(param);
			break;
		default:
			cout << "Error" << endl;
	}
}

void ScalarConverter::convert(const string& param)
{
	int type;
	literals_check(param);
	type = define_types(param);
	if (type == -1) {
		throw Error();
	}
	casting(param, type);
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
