#include "BitcoinExchange.hpp"

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

void BitcoinExchange::add_key_value(string key, string value) {
	_btc[key] = atoi(value.c_str());
}

void BitcoinExchange::print_map() {
	for (std::map<string, int>::iterator it = _btc.begin(); it != _btc.end(); it++) {
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
	}
}


