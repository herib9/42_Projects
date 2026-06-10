#pragma once
#include "ClapTrap.hpp"

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