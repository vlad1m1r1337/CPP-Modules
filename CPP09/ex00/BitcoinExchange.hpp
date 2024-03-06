#ifndef CPPMODULESPROJECT_BITCOINEXCHANGE_HPP
#define CPPMODULESPROJECT_BITCOINEXCHANGE_HPP

#include "iostream"
#include <map>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class BitcoinExchange {
private:
	std::map<string, int > _btc;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	void print_map();
	void parse_data(char *argv);
	void parse_key_value(string key, string value);
};

std::string trim(const std::string& str);
int	size_check(const char *str);
int validate_date(string date);
void	fill_data_map(std::ifstream &file, std::map<string, double> *data_csv);
#endif
