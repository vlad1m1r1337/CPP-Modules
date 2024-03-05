#include "BitcoinExchange.hpp"

//Orthodox Canonical Form

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		this->_btc = other._btc;
	}
	return *this;
}

//member functions

void BitcoinExchange::add_key_value(string key, string value) {
	_btc[key] = atoi(value.c_str());
}

void BitcoinExchange::print_map() {
	for (std::map<string, int>::iterator it = _btc.begin(); it != _btc.end(); it++) {
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	}
}

void BitcoinExchange::parse_data(BitcoinExchange &btc, char* argv) {
	string line;
	std::ifstream in(argv);
	if (in.is_open())
	{
		std::getline(in, line);
		cout << "line: " << line << endl; // "date | value
		if (line != "date | value") {
			std::cout << "Error: first line is not 'date | value'." << std::endl;
			exit(1);
		}
		while (std::getline(in, line))
		{
			string key;
			string value;
			std::stringstream ss(line);
			std::getline(ss, key, '|');

			std::getline(ss, value, '|');

			key = trim(key);
			value = trim(value);

			parse_key_value(btc, key, value);
			btc.add_key_value(key, value);
		}
	}
	in.close();
}

void BitcoinExchange::parse_key_value(BitcoinExchange &btc, string key, string value) {
	(void)btc;
	if (value[0] == '-') {
		std::cout << "Error: not a positive number." << std::endl;
	}
	else if (parse_date(key) == 0) {
		std::cout << "Error: bad input => " << value << std::endl;
	}
	else if (value.find_first_not_of(".0123456789") != std::string::npos) {
		std::cout << "Error: value is not a number." << std::endl;
	}
	else if (size_check(value.c_str()) == 0) {
		std::cout << "Error: too large a number." << std::endl;
	}
	else if (key.empty() || value.empty()) {
		std::cout << "Error: key or value is empty." << std::endl;
	}
	else
	{
		std::cout << "Key: " << key << ", Value: " << value << std::endl;
	}
}

//helper functions

int parse_date(string date) {
	size_t first_dash = date.find("-");

	string year = date.substr(0, first_dash);
	if (year.size() != 4) {
		return 0;
	}
	return 1;
}

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
		if (!(result * mcount >= 0 && result * mcount <= 1000))
			return 0;
	}
	return 1;
}


//trim functions
bool IsNotSpace(char ch) {
	return !std::isspace(ch);
}

std::string ltrim(const std::string& str) {
	std::string result = str;
	result.erase(result.begin(), std::find_if(result.begin(), result.end(), IsNotSpace));
	return result;
}


std::string rtrim(const std::string& str) {
	std::string result = str;
	result.erase(std::find_if(result.rbegin(), result.rend(), IsNotSpace).base(), result.end());
	return result;
}

std::string trim(const std::string& str) {
	return rtrim(ltrim(str));
}
