#include "Phonebook.hpp"

void ft_cmd_prompt()
{
	std::cout << std::endl
			  << "Please type one of the commands:" << std::endl
			  << "- ADD" << std::endl
			  << "- SEARCH" << std::endl
			  << "- EXIT" << std::endl
			  << std::endl;
}

int main(void)
{
	Phonebook book;
	int counter = 0;
	std::string command;

	while (1)
	{
		ft_cmd_prompt();
		getline(std::cin, command);
		if (command == "EXIT")
			exit(0);
		else if (command == "ADD")
			book.addContact(counter++);
		else if (command == "SEARCH")
		{
			book.printContacts();
			book.searchContact();
		}
		else
			std::cout << "Command not found, try again. Use capital letters." << std::endl;
		if (counter == 8)
			counter = 0;
	}
	return (0);
}