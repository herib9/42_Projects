#include "../inc/Weapon.hpp"


Weapon::Weapon(const std::string &type) : _type(type) {
}

Weapon::Weapon() : _type(""){}

Weapon::~Weapon() {
}

const std::string	&Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(const std::string &newType)
{
	this->_type = newType;
}
