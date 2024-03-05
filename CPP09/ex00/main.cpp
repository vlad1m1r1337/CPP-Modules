#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	(void)argv;
	if (argc != 2) {
		cout << "Error: could not open file." << endl;
		return 1;
	}

	BitcoinExchange btc;

	btc.parse_data(btc, argv[1]);
//	btc.print_map();
	return 0;
}

