#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		static const int maxContacts = 8;
		Contact contacts[maxContacts];
		int contactCount;

	public:
		PhoneBook();
		void addContact();
		void searchContact() const;
};

#endif
