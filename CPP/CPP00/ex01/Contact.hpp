#pragma once	// == ifndef	define	endif

#include <iostream>
#include <string>

//using std::cout; using std::endl; using std::cin;
 
class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();
		
		void		set_firstName(const std::string& name);
		std::string	get_firstName(void) const;

		void		set_lastName(const std::string& lname);
		std::string get_lastName(void) const;

		void		set_nickName(const std::string& nick);
		std::string get_nickName(void) const;

		void		set_phoneNumber(const std::string& number);
		std::string get_phoneNumber(void) const;

		void		set_darkestSecret(const std::string& secret);
		std::string get_darkestSecret(void) const;
};
