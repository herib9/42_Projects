#pragma once
#include <string>
#include <iostream>

class	ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &player);
		ClapTrap &operator=(const ClapTrap &player);
		virtual ~ClapTrap();

		virtual void attack(const std::string &target);
		void takeDamage(unsigned int healthP);
		void beRepaired(unsigned int healthP);
};