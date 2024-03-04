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
	void add_key_value(string key, string value);
};

#endif
