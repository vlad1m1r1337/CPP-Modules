#include "ScalarConverter.hpp"
#include "Error.hpp"

int is_char(string param) {
	if (param.length() == 1 && !isdigit(param[0])) {
		return 1;
	}
	return 0;
}
