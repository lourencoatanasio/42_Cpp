//
// Created by ldiogo on 4/8/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>



void	bitcoinExchange(std::vector<std::string> lines) {

}

std::vector<std::string> get_file_input(const char *fileName)
{
	std::ifstream file(fileName);
	std::vector<std::string> lines;
	std::string line;

	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << fileName << std::endl;
		return lines;
	}

	while (std::getline(file, line)) {
		lines.push_back(line);
	}

	return lines;
}

int main(int argc, char **argv)
{
	std::vector<std::string>	lines;
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}
	lines = get_file_input(argv[1], lines);
	if (lines.empty()) {
		return 1;
	}
	bitcoinExchange(lines);
	return 0;
}