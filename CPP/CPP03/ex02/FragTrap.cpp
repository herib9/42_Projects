#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

FragTrap::FragTrap() : ClapTrap(_name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\nFragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &target) : ClapTrap(target) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&FragTrap::operator=(const FragTrap &player) {
	std::cout << "FragTrap copy operator called" << std::endl;
	if(this != &player) {
		_name			= player._name;
		_hitPoints		= player._hitPoints;
		_energyPoints	= player._energyPoints;
		_attackDamage	= player._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target) {
	if(_hitPoints < 1 || _energyPoints < 1) {
		std::cout << "\nFragTrap " << _name << " cannot attack" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "\nFragTrap " << _name << " attack" << std::endl;
}


void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " wants to high-five" << std::endl;
}
