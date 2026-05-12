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
		
		void		setType(const std::string& _type);
		std::string	getType(void) const;
};
