#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("defConsFrag")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &target) : ClapTrap(target)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&FragTrap::operator=(const FragTrap &player)
{
	std::cout << "FragTrap assignement operator called" << std::endl;
	if(this != &player)
		ClapTrap::operator=(player);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "FragTrap " << this->_name << "esta MUERTO, a quien le va a chocar los 5 compae??" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->_name << " dice: choca esos cinco!!" << std::endl;
}
