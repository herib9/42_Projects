#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class	FragTrap	:	virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &player);
		FragTrap &operator=(const FragTrap &player);
		~FragTrap();

		void	attack(const std::string &target);
		void	highFivesGuys(void);
};