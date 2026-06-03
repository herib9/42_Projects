#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &player);
		ScavTrap &operator=(const ScavTrap &player);
		~ScavTrap();

		void	attack(const std::string &target);
		void	guardGate();

};