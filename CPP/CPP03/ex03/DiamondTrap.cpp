#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	_hitPoints		= FragTrap::_hitPoints;
	_energyPoints	= ScavTrap::_energyPoints;
	_attackDamage	= FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints		= FragTrap::_hitPoints;
	_energyPoints	= ScavTrap::_energyPoints;
	_attackDamage	= FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &player) : ClapTrap(player), ScavTrap(player), FragTrap(player)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &player)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if(this != &player) {
		_name			= player._name;
		_hitPoints		= player._hitPoints;
		_energyPoints	= player._energyPoints;
		_attackDamage	= player._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &player)
{
	if(_hitPoints < 1 || _energyPoints < 1) {
		std::cout << "DiamondTrap " << _name << " cannot attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "DiamondTrap " << _name << " attack " << player << " causing " << _attackDamage << " damage points" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	if(_hitPoints < 1)
		std::cout << "DiamondTrap " << _name << " is dead" << std::endl;
	else {
		std::cout << "DiamondTrap name: " << _name << std::endl;
		std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	}
}
