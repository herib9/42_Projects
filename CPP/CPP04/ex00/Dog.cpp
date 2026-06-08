#include "Dog.hpp"

Dog::Dog() : Animal("DOG")
{
	std::cout << "DOG default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "DOG constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "DOG copy constructor called" << std::endl;
}

Dog&Dog::operator=(const Dog &copy)
{
	std::cout << "DOG assignment constructor called" << std::endl;
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

Dog::~Dog()
{
	std::cout << "DOG destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "DOG barks at the hippies" << std::endl;
}
