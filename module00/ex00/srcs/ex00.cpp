#include <iostream>

int main(int argc, char **argv)
{
	int i = 1;
	int n = 0;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (argv[i])
	{
		n = 0;
		while(argv[i][n] != '\0')
		{
			std::cout << (char)std::toupper(argv[i][n]);
			n++;
		}
		i++;
		if(argv[i])
			std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}