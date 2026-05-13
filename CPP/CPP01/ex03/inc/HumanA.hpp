#pragma once

#include "Weapon.hpp"


class	HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA	(std::string name, Weapon &weapon);

		//HumanA();
		~HumanA();
		
		void	attack(void);
		void	setName(std::string	name);
		void	setWeapon(Weapon &weapon);
		//const	std::string	&getName(void) const;
		//const	Weapon &getWeapon(void) const;
};
