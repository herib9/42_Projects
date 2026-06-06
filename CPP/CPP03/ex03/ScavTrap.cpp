#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
} 

ScavTrap::ScavTrap(const ScavTrap &target) : ClapTrap(target)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&ScavTrap::operator=(const ScavTrap &player)
{
	std::cout << "ScavTrap assignement operator called" << std::endl;
	if(this != &player) {
		_name			= player._name;
		_hitPoints		= player._hitPoints;
		_energyPoints	= player._energyPoints;
		_attackDamage	= player._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if(_hitPoints < 1) {
		std::cout << "ScavTrap " << _name << " DEAD! cannot attack, no hit points" << std::endl;
		return ;
	}
	else if (_energyPoints < 1) {
	std::cout <<  "ScavTrap " << _name << " cannot attack, no energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attack " << target << " causing QUE SE MUERA" << _attackDamage << " damage points" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
