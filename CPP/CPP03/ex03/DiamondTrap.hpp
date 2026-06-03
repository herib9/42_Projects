#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ClapTrap, FragTrap, ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(int _hitPoints);
		
		DiamondTrap(const DiamondTrap &player);
		DiamondTrap &operator=(const DiamondTrap &player);
		~DiamondTrap();


		void whoAmI();
};