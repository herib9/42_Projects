#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &player);
		DiamondTrap &operator=(const DiamondTrap &player);
		~DiamondTrap();

		void	attack(const std::string &player);
		void	whoAmI();
};
