#include <fstream>
#include <iostream>
#include <string>
#include <limits>

int main(int argc, const char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <string> <substring>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);
    std::string line;
    size_t line_pos;

    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filename << std::endl;
        return 1;
    }

    std::string output = argv[1];
    output += ".replace";
    std::ofstream outfile(output);

    if (!outfile.is_open())
    {
        std::cout << "Error opening file: " << output << std::endl;
        return 1;
    }

    while (std::getline(file, line))
    {
        line_pos = line.find(argv[2]);
        if (line_pos != std::string::npos)
        {
            line.erase(line_pos, std::string(argv[2]).length());
            line.insert(line_pos, argv[3]);
            outfile << line << std::endl;
        }
        else
            outfile << line << std::endl;
    }
    outfile.close();
    file.close();
}

> eu amo te suika