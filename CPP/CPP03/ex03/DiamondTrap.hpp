#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &player);
		DiamondTrap &operator=(const DiamondTrap &player);
		virtual ~DiamondTrap();

		void	attack(const std::string &healthP);
		void	whoAmI();
};
