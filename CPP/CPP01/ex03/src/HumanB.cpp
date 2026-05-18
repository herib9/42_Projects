#include "../inc/HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL){
}

//HumanB::HumanB() : _name("") {}

HumanB::~HumanB(){
}

void	HumanB::attack(void)
{
	if (this->_weapon)
	{
		std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
	}
	else
	{
		std::cout << this->getName() << " has no weapon " << std::endl;
		return ;
	}
}

void	HumanB::setName(const std::string &name)
{
	this->_name = name;
}

const	std::string &HumanB::getName(void) const
{
	return (this->_name);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

const	Weapon &HumanB::getWeapon(void) const
{
	return (*this->_weapon);
}

