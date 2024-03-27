#include "BitcoinExchange.hpp"

//Orthodox Canonical Form

bool is_valid_date(string year, string month, string day);

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

void BitcoinExchange::print_map() {
	for (std::map<string, int>::iterator it = _btc.begin(); it != _btc.end(); it++) {
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	}
}

void BitcoinExchange::parse_data(char *argv) {
	string line;
	std::ifstream in(argv);
	if (in.is_open())
	{
		std::getline(in, line);
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
			if (key.length() != 10) {
				std::cout << "Error: key is not valid." << std::endl;
				continue;
			}

			value = trim(value);
			if ((std::count(value.begin(), value.end(), '.')) > 1) {
				std::cout << "Error: value is not valid." << std::endl;
				continue;
			}
			if (!key.length() || !value.length()) {
				std::cout << "Error: key or value is empty." << std::endl;
				continue;
			}
			parse_key_value(key, value);
		}
	}
	in.close();
}

void non_existing_date(string key, string value, std::map<string, double> data_csv) {
	string year_input = key.substr(0, 4);
	string month_input = key.substr(5, 2);
	string day_input = key.substr(8, 2);

	for (std::map<string, double>::iterator it = data_csv.begin(); it != data_csv.end(); it++) {
		double temp;
		string date = it->first;
		string year_from_data = date.substr(0, 4);
		string month_from_data = date.substr(5, 2);
		string day_from_data = date.substr(8, 2);
		if (it == data_csv.begin()) {
			temp = it->second;
		}
		if (date > key) {
			it--;
			cout << key << " => " << value << " => " << it->second * atof(value.c_str()) << endl;
			return ;
		}
		if (year_from_data == year_input) {
			if (month_from_data == month_input) {
				if (day_input < day_from_data) {
					cout << key << " => " << value << " => " << temp * atof(value.c_str()) << endl;
					return;
				}
			}
		}
		temp = it->second;
	}
    std::map<string, double>::reverse_iterator rit = data_csv.rbegin();
    cout << key << " => " << value << " => " << rit->second * atof(value.c_str()) << endl;
}

void	fill_data_map(std::ifstream &file, std::map<string, double> *data_csv) {
	string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		int pos = line.find(",");
		string date = line.substr(0, pos);
		string value_from_data = line.substr(pos + 1, line.length() - pos);
		(*data_csv)[date] = atof(value_from_data.c_str());
	}
}

void	output(string key, string value) {
	(void)key;
	(void)value;
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}

	std::map<string, double> data_csv;
	fill_data_map(file, &data_csv);

	std::map<string, double>::iterator it = data_csv.find(key);

	if (it != data_csv.end()) {
		double res = data_csv[key] * atof(value.c_str());
		cout << key << " => " << value << " => " << res << endl;
	}
	else {
		non_existing_date(key, value, data_csv);
	}
	file.close();
}

void BitcoinExchange::parse_key_value(string key, string value) {
    if (value[value.length() - 1] == 'f') {
        value = value.substr(0, value.length() - 1);
    }
	if (value[0] == '-') {
		std::cout << "Error: not a positive number." << std::endl;
	}
	else if (validate_date(key) == 0) {
		std::cout << "Error: bad input => " << key << std::endl;
	}
	else if (value.find_first_not_of(".0123456789") != std::string::npos || value[0] == '.') {
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
		output(key, value);
	}
}

//helper functions

int validate_lap_year(string year, string month, string day) {
	if (atoi(year.c_str()) % 4 == 0) {
		if (atoi(year.c_str()) % 100 == 0) {
			if (atoi(year.c_str()) % 400 == 0) {
				if (atoi(month.c_str()) == 2 && atoi(day.c_str()) > 29) {
					return 1;
				}
			}
			else {
				if (atoi(month.c_str()) == 2 && atoi(day.c_str()) > 28) {
					return 1;
				}
			}
		}
		else {
			if (atoi(month.c_str()) == 2 && atoi(day.c_str()) > 29) {
				return 1;
			}
		}
	}
	return 0;
}

int validate_date(string date) {
    if (date[7] != '-' || date[4] != '-') {
        return 0;
    }
	size_t first_dash = date.find("-");

	string year = date.substr(0, first_dash);
	string month = date.substr(first_dash + 1, 2);
	string day = date.substr(first_dash + 4, 2);

	if (year.length() != 4 || month.length() != 2 || day.length() != 2) {
		return 0;
	}
	if (year.find_first_not_of("0123456789") != std::string::npos || month.find_first_not_of("0123456789") != std::string::npos || day.find_first_not_of("0123456789") != std::string::npos) {
		return 0;
	}
	if (atoi(year.c_str()) < 2009) {
		return 0;
	}
	if (year == "2009" && month == "01" && day == "01") {
		return 0;
	}
	if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12) {
		return 0;
	}
	if (atoi(day.c_str()) < 1 || atoi(day.c_str()) > 31) {
		return 0;
	}
	if (validate_lap_year(year, month, day)) {
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
