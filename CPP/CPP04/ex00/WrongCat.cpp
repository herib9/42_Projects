#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

/* WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat constructor called" << std::endl;
} */

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if(this != &copy)
		WrongAnimal::operator=(copy);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat dice que pasa de maullar" << std::endl;
}
