#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	_hitPoints		= FragTrap::_hitPoints;
	_energyPoints	= ScavTrap::_energyPoints;
	_attackDamage	= FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	_hitPoints		= FragTrap::_hitPoints;
	_energyPoints	= ScavTrap::_energyPoints;
	_attackDamage	= FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &player) : ScavTrap(player), FragTrap(player)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name			= player._name;
	_hitPoints		= player._hitPoints;
	_energyPoints	= player._energyPoints;
	_attackDamage	= player._attackDamage;
	*this = player;
	//return 
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &player)
{
	std::cout << "DiamondTrap assignement assignment operator called" << std::endl;
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

/* void	DiamondTrap::attack(const std::string &target) {
	if(_hitPoints < 1) {
		std::cout << "DiamondTrap " << _name << " DEAD! cannot attack, no hit points" << std::endl;
		return ;
	}
	else if (_energyPoints < 1) {
	std::cout <<  "DiamondTrap " << _name << " cannot attack, no energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "DiamondTrap " << _name << " attack " << target << " causing " << _attackDamage << " damage points" << std::endl;
} */


void	DiamondTrap::attack(const std::string &healthP)
{
	std::cout << "EL MENSAJE DE SU PUTA MADRE" << std::endl;
	return (ScavTrap::attack(healthP));
}

void	DiamondTrap::whoAmI()
{
	if(_hitPoints < 1)
		std::cout << "DiamondTrap " << _name << " doesn't know who he is, is dead" << std::endl;
	else if (_energyPoints < 1)
		std::cout << "DiamondTrap " << _name << " cannot see who he is, no energy points" << std::endl;
	else {
		std::cout << "DiamondTrap name: " << _name << std::endl;
		std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	}
}
