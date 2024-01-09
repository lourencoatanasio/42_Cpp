#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	void setContactInfo();
	void displayContact(int index) const;
	void displayContactInLines() const;
};

#endif
