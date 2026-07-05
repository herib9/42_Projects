#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("")
{
	std::cout << "ANIMAL default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "ANIMAL constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) : _type(copy._type)
{
	std::cout << "ANIMAL copy constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "ANIMAL destructor called" << std::endl;
}

AAnimal&AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "ANIMAL assignment operator called" << std::endl;
	if(this != &copy)
		this->_type = copy._type;
	return *this;
}

const std::string &AAnimal::getType(void) const
{
	return this->_type;
}
