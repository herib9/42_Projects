#pragma once

#include "Weapon.hpp"


class	HumanB
{
	private:
		std::string	_name;
		Weapon 		*_weapon;

	public:
		HumanB	(std::string	name);
		//HumanB();
		~HumanB();

		void	attack(void);
		void	setName(std::string name);
		void	setWeapon(Weapon &weapon);
		const	std::string &getName(void) const;
		const	Weapon &getWeapon(void) const;
};
