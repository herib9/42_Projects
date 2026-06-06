#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &target) : ClapTrap(target)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&FragTrap::operator=(const FragTrap &player)
{
	std::cout << "FragTrap assignement operator called" << std::endl;
	if(this != &player) {
		_name			= player._name;
		_hitPoints		= player._hitPoints;
		_energyPoints	= player._energyPoints;
		_attackDamage	= player._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}
/* 
void	FragTrap::attack(const std::string &target) {
	if(_hitPoints < 1) {
		std::cout << "FragTrap " << _name << " DEAD! cannot attack, no hit points" << std::endl;
		return ;
	}
	else if (_energyPoints < 1) {
	std::cout <<  "FragTrap " << _name << " cannot attack, no energy points" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attack " << target << " causing " << _attackDamage << " damage points" << std::endl;
}
 */

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " wants to high-five" << std::endl;
}
