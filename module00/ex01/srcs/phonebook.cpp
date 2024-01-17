#include "../inc/header.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact()
{
	for (int i = maxContacts - 1; i > 0; --i)
		contacts[i] = contacts[i - 1];
	contacts[0].setContactInfo(); // Add the new contact to the top
	++contactCount;
}

void PhoneBook::searchContact() const
{
	int index;

	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}

	std::cout << std::setw(10) << std::right << "Index";
	std::cout << "|" << std::setw(10) << std::right << "First Name";
	std::cout << "|" << std::setw(10) << std::right << "Last Name";
	std::cout << "|" << std::setw(10) << std::right << "Nickname";
	std::cout << std::endl;

	for (int i = 0; i < contactCount && i < maxContacts; ++i)
		contacts[i].displayContact(i);

	while (1)
	{
		std::cout << "Enter index: ";
		std::cin >> index;
		if (std::cin.fail() || index < 0 || index >= contactCount)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index. Please enter a valid index." << std::endl;
		}
		else
			break;
	}

	if (index >= 0 && index < contactCount)
	{
		std::cout << "Contact details:" << std::endl;
		contacts[index].displayContactInLines();
	}
	else
		std::cout << "Invalid index. Please enter a valid index." << std::endl;
}

int PhoneBook::getContactCount()
{
    return contactCount;
}