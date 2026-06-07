#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class	FragTrap	:	public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &player);
		FragTrap &operator=(const FragTrap &player);
		~FragTrap();

		void	highFivesGuys(void);
};