

int	int_check (const char *str) {
	int mcount;
	int i;
	long result;

	i = 0;
	result = 0;
	mcount = 1;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-') {
		mcount = mcount * (-1);
		i++;
	} else if (str[i] == '+')
		i++;
	while (str[i] <= 9 + '0' && str[i] >= 0 + '0') {
		result = 10 * result + str[i] - '0';
		i++;
		if (!(result * mcount >= -2147483648 && result * mcount <= 2147483647))
			return 1;
	}
	return 0;
}