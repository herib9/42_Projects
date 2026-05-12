#pragma once

#include <string>
#include <iostream>


class	Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);

		Weapon();
		~Weapon();
		
		std::string	getType(void) const;
		void		setType(const std::string &newType);
};
