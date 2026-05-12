#include "PhoneBook.hpp"

int main	(void)
{
	PhoneBook	phonebook;
	std::string input;

	while(1)
	{
		std::cout << "Please, select one of these options: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if(input == "ADD")
			phonebook.addContact();
		else if(input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break;
	}
	return 0;
}
