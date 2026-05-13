#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){
}

//HumanB::HumanB() : _name("") {}

HumanB::~HumanB(){
}

void	HumanB::attack(void)
{
	if (!(_weapon))
		std::cout << this->getName() << " has no weapon " << std::endl;
	else
		std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}

void	HumanB::setName(std::string name)
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

