#pragma once

#include "Weapon.hpp"


class	HumanB
{
	private:
		std::string	_name;

	public:
		HumanB	(std::string	name);
		HumanB();
		~HumanB();

		void	setName(std::string name);
};
