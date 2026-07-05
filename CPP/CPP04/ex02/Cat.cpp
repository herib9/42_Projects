#include "Cat.hpp"

Cat::Cat() : AAnimal("CAT")
{
	std::cout << "- CAT default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(std::string type) : AAnimal(type)
{
	std::cout << "- CAT constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	std::cout << "- CAT copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this->_brain = *copy._brain;
}

Cat::~Cat()
{
	std::cout << "- CAT destructor called" << std::endl;
	delete _brain;
}

Cat&Cat::operator=(const Cat &copy)
{
	std::cout << "- CAT assignment operator called" << std::endl;
	if(this != &copy)
	{
		AAnimal::operator=(copy);
		*this->_brain = *copy._brain;
	}
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "CAT purrs to heal" << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}
