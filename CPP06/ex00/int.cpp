#include "ScalarConverter.hpp"
#include "Error.hpp"

int	size_check(const char *str)
{
	int		mcount;
	int		i;
	long	result;

	i = 0;
	result = 0;
	mcount = 1;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-')
	{
		mcount = mcount * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= 9 + '0' && str[i] >= 0 + '0')
	{
		result = 10 * result + str[i] - '0';
		i++;
		if (!(result * mcount >= -2147483648 && result * mcount <= 2147483647))
			return 0;
	}
	return 1;
}

int are_after_dot_zeros(string param) {
	int i = -1;
	while(param[++i] != '.');
	while(param[++i]) {
		if (param[i] != '0') {
			return 0;
		}
	}
	return 1;
}

int dot_finder(string param) {
	int i = 0;
	while(param[i]) {
		if (param[i] == '.') {
			return 1;
		}
		i++;
	}
	return 0;
}

int symbol_check(string param) {
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

int is_int(string param) {
	if (symbol_check(param) == 0) {
		return 0;
	}
	if(dot_finder(param)) {
		if (!are_after_dot_zeros(param)) {
			return 0;
		}
	}
	if (size_check(param.c_str())) {
		return 1;
	}
	else
		return 0;
}
