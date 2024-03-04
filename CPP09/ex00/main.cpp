#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Error: could not open file." << endl;
	}
	BitcoinExchange btc;
	string line;
	std::ifstream in(argv[1]);
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			string key;
			string value;
			std::stringstream ss(line);
			std::getline(ss, key, ',');

			std::getline(ss, value, ',');

			btc.add_key_value(key, value);
		}
	}
	in.close();
	btc.print_map();
	return 0;
}
