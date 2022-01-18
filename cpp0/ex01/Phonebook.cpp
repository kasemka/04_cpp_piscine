#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	std::cout << std::endl
			  << "***  Welcome to the phonebook  ***" << std::endl;
	this->_initEmptyPhonebook();
	return;
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook destructor called" << std::endl;
	return;
}

void Phonebook::addFirstName(Contact *contact)
{
	std::string valid_str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	while (1)
	{
		std::cout << "ENTER FIRST NAME: ";
		getline(std::cin, contact->firstName);
		if (contact->firstName.empty())
			std::cout << "Name cannot be empty" << std::endl;
		else if (contact->firstName.find_first_not_of(valid_str) != std::string::npos)
			std::cout << "Invalid symbols found. Please try again" << std::endl;
		else
			break;
	}
	return ;
}

void Phonebook::addLastName(Contact *contact)
{
	while (1)
	{
		std::cout << "ENTER LAST NAME: ";
		getline(std::cin, contact->lastName);
		if (contact->lastName.empty())
			std::cout << "Last name cannot be empty" << std::endl;
		else
			break;
	}
}

void Phonebook::addNickname(Contact *contact)
{
	while (1)
	{
		std::cout << "ENTER NICKNAME: ";
		getline(std::cin, contact->nickname);
		if (contact->nickname.empty())
			std::cout << "Nickname cannot be empty" << std::endl;
		else
			break;
	}
}

void Phonebook::addPhoneNumber(Contact *contact)
{
	while (1)
	{
		std::cout << "ENTER PHONENUMBER: ";
		getline(std::cin, contact->phoneNumber);
		if (contact->phoneNumber.empty())
			std::cout << "Phonenumber cannot be empty" << std::endl;
		else if (contact->phoneNumber.find_first_not_of("0123456789") != std::string::npos)
			std::cout << "Invalid symbols found. Please try again" << std::endl;
		else
			break;
	}
}

void Phonebook::addDarkestSecret(Contact *contact)
{
	while (1)
	{
		std::cout << "ENTER DARKEST SECRET: ";
		getline(std::cin, contact->darkestSecret);
		if (contact->darkestSecret.empty())
			std::cout << "Darkest secret cannot be empty" << std::endl;
		else
			break;
	}
}

void Phonebook::addContact(int ind)
{
	addFirstName(&_contacts[ind]);
	addLastName(&_contacts[ind]);
	addNickname(&_contacts[ind]);
	addPhoneNumber(&_contacts[ind]);
	addDarkestSecret(&_contacts[ind]);
	_contacts[ind].index = ind + 1;
	std::cout << "Contact was added" << std::endl;
	return;
}

void Phonebook::_printTableRow(Contact contact) const
{
	std::string new_first_name = contact.firstName.substr(0, 9);
	std::string new_last_name = contact.lastName.substr(0, 9);
	std::string new_nickname = contact.nickname.substr(0, 9);

	std::cout << std::right << "|" << std::setw(10) << contact.index << "|";
	if (contact.firstName.length() < 10)
		std::cout << std::right << std::setw(10) << new_first_name << "|";
	else
		std::cout << std::right << std::setw(9) << new_first_name << "."
				  << "|";
	if (contact.lastName.length() < 10)
		std::cout << std::right << std::setw(10) << new_last_name << "|";
	else
		std::cout << std::right << std::setw(9) << new_last_name << "."
				  << "|";
	if (contact.nickname.length() < 10)
		std::cout << std::right << std::setw(10) << new_nickname << "|";
	else
		std::cout << std::right << std::setw(9) << new_nickname << "."
				  << "|";
	std::cout << std::endl;
	std::cout << std::string(45, '-') << std::endl;
}

void Phonebook::printContacts(void) const
{
	int i = 0;

	if (_contacts[0].index == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	std::cout << std::string(45, '-') << std::endl
			  << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	while (_contacts[i].index > 0 && _contacts[i].index < 9 && i < 9)
		_printTableRow(_contacts[i++]);
}

void Phonebook::searchContact(void) const
{
	int index;
	int i = 0;

	if (_contacts[0].index == 0)
		return;
	std::cout << "Please choose the index of the contact: ";
	std::cin >> index;
	if (!std::cin.good())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "invalid index!" << std::endl;
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (i < 8 && _contacts[i].index != index)
		i++;
	if (i > 7 || index < 1)
		std::cout << "Index not found" << std::endl;
	else
	{
		std::cout << std::endl
				  << "Contact information:" << std::endl
				  << "first name: " << _contacts[i].firstName << std::endl
				  << "last name: " << _contacts[i].lastName << std::endl
				  << "nickname: " << _contacts[i].nickname << std::endl
				  << "phone number: " << _contacts[i].phoneNumber << std::endl
				  << "darkest secret: " << _contacts[i].darkestSecret << std::endl;
	}
	return;
}

void Phonebook::_initEmptyPhonebook(void)
{
	int i = 0;

	while (i < 8)
		_contacts[i++].index = 0;
}