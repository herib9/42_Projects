#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_contactCount = 0;
	_nextIndex = 0;
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::addContact()
{
	std::string	input;

	static int i = 0;

	if(i == 8)
		i = 0;

	std::cout << "Enter a name: ";
	if (std::getline(std::cin, input) && input.empty())
		std::cout << "This field cannot be empty, please enter a name: ";
	else
	{
		int	k = 0;
		while (k < (int)input.length())
		{
			if(input[k] == '\t')
				input[k] = ' ';
			k++;
		}
		this->_contacts[i].set_firstName(input);
		//std::cout << this->_contacts[i].get_firstName() << std::endl;
	if (!std::cin)
		return;
	}

	std::cout << "Enter a last name: ";
	if (std::getline(std::cin, input) && input.empty())
		std::cout << "This field cannot be empty, please enter a last name: ";
	else
	{
		int	k = 0;
		while (k < (int)input.length())
		{
			if(input[k] == '\t')
				input[k] = ' ';
			k++;
		}
		this->_contacts[i].set_lastName(input);
	}
	if (!std::cin)
		return;

	std::cout << "Enter a nick name: ";
	if (std::getline(std::cin, input) && input.empty())
		std::cout << "This field cannot be empty, please enter a nick name: ";
	else
	{
		int	k = 0;
		while (k < (int)input.length())
		{
			if(input[k] == '\t')
				input[k] = ' ';
			k++;
		}
	}
		this->_contacts[i].set_nickName(input);
	if (!std::cin)
		return;

	std::cout << "Enter a phone number: ";
	if (std::getline(std::cin, input) && input.empty())
		std::cout << "This field cannot be empty, please enter a phone number: ";
	else
		this->_contacts[i].set_phoneNumber(input);
	if (!std::cin)
		return;

	std::cout << "Enter a darkest secret: ";
	if (std::getline(std::cin, input) && input.empty())
		std::cout << "This field cannot be empty, please enter a darkest secret: ";
	else
	{
		int	k = 0;
		while (k < (int)input.length())
		{
			if(input[k] == '\t')
				input[k] = ' ';
			k++;
		}
	}
		this->_contacts[i].set_darkestSecret(input);
	if (!std::cin)
		return;

	_contactCount++;
	i++;
}

void	PhoneBook::searchContact() const
{
	int i = 0;

	std::cout << "|     " << "INDEX" << "|";
	std::cout << "      NAME" << "|";
	std::cout << " LAST NAME" << "|";
	std::cout << "  NICKNAME" << "|"<< std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	
	while(i < _contactCount)
	{
		std::cout << "|         " << i + 1 << "|";
		std::cout << std::setw(10) << this->_contacts[i].get_firstName() << "|";
		std::cout << std::setw(10) << this->_contacts[i].get_lastName() << "|";
		std::cout << std::setw(10) << this->_contacts[i].get_nickName() << "|" << std::endl;
		i++;
	}
	
}
