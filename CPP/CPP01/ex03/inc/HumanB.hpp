#pragma once

#include "Weapon.hpp"
#include <string>


class	HumanB
{
	private:
		std::string	_name;
		Weapon 		*_weapon;

	public:
		HumanB	(const std::string &name);
		//HumanB();
		~HumanB();

		void	attack(void);
		void	setName(const std::string &name);
		void	setWeapon(Weapon &weapon);
		const	std::string &getName(void) const;
		const	Weapon &getWeapon(void) const;
};
