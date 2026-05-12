#pragma once

#include "Weapon.hpp"


class	HumanA
{
	private:
		std::string	_name;
		std::string	_weapon;

	public:
		HumanA	(std::string	name);
		HumanA	(std::string	weapon);
		HumanA();
		~HumanA();
		void	attack(void);
		void	setName(std::string	name);
		void	setWeapon(std::string weapon);
};
