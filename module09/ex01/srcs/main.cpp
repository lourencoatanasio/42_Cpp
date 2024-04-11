//
// Created by ldiogo on 4/8/24.
//

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}
    BitcoinExchange bitcoinExchange;
//    values = get_file_input("data.csv", values);
//	lines = get_file_input(argv[1], lines);
//	if (lines.empty()) {
//		return 1;
//	}
//    bitcoinExchange(values, lines);
	return 0;
}
