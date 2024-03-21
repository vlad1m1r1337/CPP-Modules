#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	(void)argv;
	if (argc != 2) {
		cout << "Error: could not open file." << endl;
		return 1;
	}

	BitcoinExchange btc;

	btc.parse_data(argv[1]);
	return 0;
}
