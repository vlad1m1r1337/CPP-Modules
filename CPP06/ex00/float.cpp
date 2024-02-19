#include "ScalarConverter.hpp"
#include "Error.hpp"

int symbol_check_float(string param) {
	int i = 0;
	if (param[param.length() - 1] != 'f') {
		return 0;
	}
	while(param[++i - 1]) {
		if (!isdigit(param[i])) {
			return 0;
		}
	}
	return 1;
}

int is_float(string param) {
	if (symbol_check_float(param) == 0) {
		return 0;
	}
	return 1;
}