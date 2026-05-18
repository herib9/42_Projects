#pragma once

#include <string>
#include "Weapon.hpp"


class	HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA	(const std::string &name, Weapon &weapon);

		//HumanA();
		~HumanA();
		
		void	attack(void);
		void	setName(const std::string &name);
		//void	setWeapon(Weapon &weapon);
		//const	std::string	&getName(void) const;
		//const	Weapon &getWeapon(void) const;
};
