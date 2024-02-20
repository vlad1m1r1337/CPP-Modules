#include "ScalarConverter.hpp"
#include "Error.hpp"

int symbol_check_double(string param) {
	int i = -1;
	if (param[0] == '-') {
		i++;
	}
	while(param[++i]) {
		if (!isdigit(param[i]) && param[i] != '.') {
			return 0;
		}
	}
	return 1;
}

int is_double(string param) {
	if (symbol_check_double(param) == 0) {
		return 0;
	}
	return 1;
}