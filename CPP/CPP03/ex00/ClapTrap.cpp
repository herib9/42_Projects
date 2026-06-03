#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &player) {
	std::cout << "Copy constructor called" << std::endl;
	*this = player;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &player) {
	std::cout << "Copy operator called" << std::endl;
	if(this != &player) {
		_name 			= player._name;
		_hitPoints 		= player._hitPoints;
		_energyPoints 	= player._energyPoints;
		_attackDamage 	= player._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if(_hitPoints < 1 || _energyPoints < 1) {
		std::cout << "ClapTrap " << _name << " cannot attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attack " << target << " causing " << _attackDamage << " damage points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " took " << amount << " damage points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints < 1) {
		std::cout << "ClapTrap " << _name << " is dead, cannot hit points" << std::endl;
		return ;
	}
	else if (_energyPoints < 1)	{
		std::cout << "ClapTrap " << _name << "cannot repair, 0 energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " healed " << amount << " hit points" << std::endl;
}
