# pragma once	// == ifndef	define	endif

#include "Contact.hpp"
#include <iostream>				//std::cout		std::cin
#include <iomanip>				//std::setw
#include <string>
#include <cctype>				//std::isdigit	std::isspace
#include <sstream>

class	PhoneBook				//clase que gestiona la agenda de tamaño fijo
{
	private:					//zona privada (datos internos)
		Contact _contacts[8];	//array 8 contactos
		int		_contactCount;	//num de contactos guardados
		int		_nextIndex;		//pos a sobrescribir cuando ya hay 8

	public:
		PhoneBook();
		~PhoneBook();
		
		void	addContact();
		void	searchContact() const;
		
		std::string truncate(std::string str) const;
		std::string Tab2Space(std::string input);
		std::string checkEmptyName(std::string message);
		std::string checkEmptyPhone(std::string message);
		std::string checkOnlyLetters(std::string message);
};
