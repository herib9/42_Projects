#include "../inc/HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon){
}

//HumanA::HumanA() : _name(""), _weapon(NULL) {}

HumanA::~HumanA() {
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void	HumanA::setName(const std::string &name)
{
	this->_name = name;
}

/*const	std::string	&HumanA::getName(void) const
{
	return (this->_name);
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}

const	Weapon &HumanA::getWeapon(void) const
{
	return this->_weapon;
}*/
