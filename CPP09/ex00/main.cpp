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

//int main() {
//	BitcoinExchange btc;
//	std::ifstream file("data.csv");
//	if (!file.is_open()) {
//		std::cout << "Error: could not open file." << std::endl;
//		exit(1);
//	}
//	std::map<string, double> data_csv;
//	fill_data_map(file, &data_csv);
//
//	return 0;
//}
