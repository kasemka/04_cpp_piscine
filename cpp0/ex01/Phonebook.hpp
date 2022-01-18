#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>

class Phonebook
{
private:
	Contact _contacts[8];
	void _printTableRow(Contact person) const;
	void _initEmptyPhonebook(void);
	void addFirstName(Contact *contact);
	void addLastName(Contact *contact);
	void addNickname(Contact *contact);
	void addPhoneNumber(Contact *contact);
	void addDarkestSecret(Contact *contact);

public:
	Phonebook(void);
	~Phonebook(void);

	void addContact(int ind);
	void printContacts(void) const;
	void searchContact(void) const;
};

int main(void);

#endif