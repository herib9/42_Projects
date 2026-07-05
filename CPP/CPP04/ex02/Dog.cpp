#include "Dog.hpp"

Dog::Dog() : AAnimal("DOG")
{
	std::cout << "- DOG default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(std::string type) : AAnimal(type)
{
	std::cout << "- DOG constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	std::cout << "- DOG copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this->_brain = *copy._brain;
}

Dog::~Dog()
{
	std::cout << "- DOG destructor called" << std::endl;
	delete _brain;
}

Dog&Dog::operator=(const Dog &copy)
{
	std::cout << "- DOG assignment operator called" << std::endl;
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		*this->_brain = *copy._brain;
	}
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "DOG barks at the hippies" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->_brain;
}
