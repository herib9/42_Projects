#include "Cat.hpp"

Cat::Cat() : Animal("CAT")
{
	std::cout << "CAT default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "CAT constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "CAT copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "CAT destructor called" << std::endl;
}

Cat&Cat::operator=(const Cat &copy)
{
	std::cout << "CAT assignment operator called" << std::endl;
	if(this != &copy)
		Animal::operator=(copy);
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "CAT purrs to heal" << std::endl;
}