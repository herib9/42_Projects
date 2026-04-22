# pragma once	// == ifndef	define	endif

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class	PhoneBook
{
	private:
		Contact _contacts[8];
		int		_contactCount;	//num de contactos guardados
		int		_nextIndex;		//pos a sobrescribir cuando ya hay 8

	public:
		PhoneBook();
		~PhoneBook();
		
		void	addContact();
		void	searchContact() const;
};
