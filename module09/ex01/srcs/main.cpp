//
// Created by ldiogo on 4/8/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdlib>

std::vector<std::string> split(const std::string& s, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

std::map<std::string, float> get_file_input(const std::string &fileName, std::map<std::string, float>& lines)
{
	std::ifstream file(fileName.c_str());
	std::string line;

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << fileName << std::endl;
		return lines;
	}

	while (std::getline(file, line))
	{
		std::vector<std::string> tokens = split(line, '|');
		if (tokens.size() != 2)
		{
			std::cout << tokens[0] << std::endl;
			std::cerr << "Error: Invalid input file" << std::endl;
			lines.clear();
			return lines;
		}
		lines[tokens[0]] = std::atof(tokens[1].c_str());
	}

	file.close();
	return lines;
}

int main(int argc, char **argv)
{
	std::map<std::string, float> lines;
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 1;
	}
	lines = get_file_input(argv[1], lines);
	if (lines.empty()) {
		return 1;
	}
	// bitcoinExchange(lines); // Uncomment this when implementing the function
	return 0;
}
