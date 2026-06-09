#include "Animal.hpp"

Animal::Animal(): _type("")
{
	std::cout << "ANIMAL default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "ANIMAL constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	std::cout << "ANIMAL copy constructor called" << std::endl;
}

Animal&Animal::operator=(const Animal &copy)
{
	std::cout << "ANIMAL assignment operator called" << std::endl;
	if(this != &copy)
		this->_type = copy._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "ANIMAL destructor called" << std::endl;
}

const std::string &Animal::getType(void) const
{
	return this->_type;
}

void Animal::makeSound(void) const
{
	std::cout << "ANIMAL SOUND SYSTEM DJING" << std::endl;
}
