#include "../inc/header.hpp"

int main()
{
	PhoneBook phonebook;

	while (true)
	{
		std::cin.clear();
		std::string command;
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			phonebook.addContact();
			std::cin.clear();
		}
		else if (command == "SEARCH")
		{
            if (phonebook.getContactCount() == 0)
                std::cout << "Phonebook is empty." << std::endl;
            else
            {
                phonebook.searchContact();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting the phonebook. Goodbye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
			std::cin.clear();
		}
	}
	return 0;
}