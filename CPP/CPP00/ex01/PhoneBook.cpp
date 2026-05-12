#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_contactCount = 0;
	_nextIndex = 0;
}

PhoneBook::~PhoneBook() 
{
}

std::string PhoneBook::Tab2Space(std::string input)
{
	int	i = 0;

	while(input[i])
	{
		if(input[i] == '\t')
			input[i] = ' ';
		i++;
	}
	return (input);
}

std::string PhoneBook::checkEmptyName(std::string message)
{
	std::string input;

	while(input.empty())
	{
		std::cout << message;
		std::getline(std::cin, input);
		input = Tab2Space(input);
		if(input.empty())
			std::cout << "This field cannot empty" << std::endl;
	}
	return (input);
}

std::string PhoneBook::checkEmptyPhone(std::string message)
{
	std::string input;

	while(input.empty())
	{
		std::cout << message;
		std::getline(std::cin, input);
		if(input.empty())
		{
			std::cout << "This field cannot empty" << std::endl;
			continue ;
		}
		int i = 0;
		int valid = 1;
		while(input[i])
		{
			if(!(input[i] >= '0' && input[i] <= '9'))
			{
				std::cout << "Input only accept numbers" << std::endl;
				valid = 0;
				break;
			}
			i++;
		}
		if(valid == 0)
			input = "";
	}
	return (input);
}

std::string PhoneBook::checkOnlyLetters(std::string message)
{
	std::string				input;
	std::string::size_type	i;
	bool					valid;

	while(input.empty())
	{
		std::cout << message;
		std::getline(std::cin, input);
		input = Tab2Space(input);
		if(input.empty())
		{
			std::cout << "This field cannot be empty" << std::endl;
			continue ;
		}
		valid = true;
		i = 0;
		while(i < input.length())
		{
			if((input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z') && input[i] == 60)
			{
				valid = false;
				break ;
			}
			i++;
		}
		if(!valid)
		{
			std::cout << "Only letters [a-z] or [A-Z]" << std::endl;
			input.clear();
		}
	}
	return (input);
}

void	PhoneBook::addContact()
{
	static int i = 0;

	i = _nextIndex;

	this->_contacts[i].set_firstName(checkOnlyLetters("Enter a name: "));
	this->_contacts[i].set_lastName(checkOnlyLetters("Enter a last name: "));
	this->_contacts[i].set_nickName(checkOnlyLetters("Enter a nick name: "));
	this->_contacts[i].set_phoneNumber(checkEmptyPhone("Enter a phone number: "));
	this->_contacts[i].set_darkestSecret(checkOnlyLetters("Enter a darkest secret: "));

	_nextIndex = (_nextIndex + 1) % 8;
	if(_contactCount < 8)
		_contactCount++;
}

void	PhoneBook::searchContact() const
{
	int			i = 0;
	std::string	input;
	int			index;

	if (_contactCount == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}

	std::cout << "|     " << "INDEX" << "|";
	std::cout << "      NAME" << "|";
	std::cout << " LAST NAME" << "|";
	std::cout << "  NICKNAME" << "|"<< std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;

	while(i < _contactCount)
	{
		std::cout << "|         " << i + 1 << "|";
		std::cout << std::setw(10) << this->truncate(_contacts[i].get_firstName()) << "|";
		std::cout << std::setw(10) << this->truncate(_contacts[i].get_lastName()) << "|";
		std::cout << std::setw(10) << this->truncate(_contacts[i].get_nickName()) << "|" << std::endl;
		i++;
	}
	while(1)
	{
		std::cout << "Enter index: ";
		std::getline(std::cin, input);
		if(input.empty())
		{
			std::cout << "Index cannot be empty" << std::endl;
			continue;
		}
		std::stringstream ss(input);
		ss >> index;
		if(ss.fail() || !ss.eof())
		{
			std::cout << "Invalid index" << std::endl;
			continue;
		}
		if(index < 1 || index > _contactCount)
		{
			std::cout << "Index out of range" << std::endl;
			continue;
		}
		index--;
		std::cout << "First name: " << _contacts[index].get_firstName() << std::endl;
		std::cout << "Last name: " << _contacts[index].get_lastName() << std::endl;
		std::cout << "Nickname: " << _contacts[index].get_nickName() << std::endl;
		std::cout << "Phone number: " << _contacts[index].get_phoneNumber() << std::endl;
		std::cout << "Darkest secret: " << _contacts[index].get_darkestSecret() << std::endl;
		break;
	}

}
std::string PhoneBook::truncate(std::string str) const
{
	if(str.length() > 10)
		str = str.substr(0, 9) + '.';
	return str;
}
