#include "../inc/header.hpp"
#include "../inc/contact.hpp"

void Contact::setContactInfo()
{
	while (1)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstName);
		if (isStringAlpha(firstName) == true && firstName.length() > 0)
			break;
		std::cout << "This is an invalid nickname" << std::endl;
	}

	while (1)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastName);
		if (isStringAlpha(lastName) == true && lastName.length() > 0)
			break;
		std::cout << "This is an invalid nickname" << std::endl;
	}

	while (1)
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
		if (nickname.length() > 0 && isStringAlphaNumeric(nickname) == true)
			break;
		std::cout << "This is an invalid nickname" << std::endl;
	}

	while (1)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, phoneNumber);
		if (isStringDigit(phoneNumber) == true && phoneNumber.length() > 0)
			break;
		std::cout << "Invalid phone number. Please enter a valid phone number." << std::endl;
	}

	while (1)
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkestSecret);
		if (darkestSecret.length() > 0 && isStringAlphaNumeric(darkestSecret) == true)
			break;
		std::cout << "This field has to be filled." << std::endl;
	}
}

void Contact::displayContactInLines() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

void Contact::displayContact(int index) const
{
	std::cout << std::setw(10) << std::right << index;
	std::cout << "|" << std::setw(10) << std::right << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName);
	std::cout << "|" << std::setw(10) << std::right << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName);
	std::cout << "|" << std::setw(10) << std::right << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname);
	std::cout << std::endl;
}