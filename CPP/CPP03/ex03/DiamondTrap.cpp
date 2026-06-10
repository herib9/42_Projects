#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("defConsTrap_clap_name"), ScavTrap(), FragTrap()
{
	this->_name			= "defConsTrap";
	this->_hitPoints	= FragTrap::_hitPoints;
	this->_energyPoints	= 50;
	this->_attackDamage	= FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name			= name;
	this->_hitPoints	= FragTrap::_hitPoints;
	this->_energyPoints	= 50;
	this->_attackDamage	= FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &player) : ScavTrap(player), FragTrap(player)
{
	this->_name			= player._name;
	this->_hitPoints	= player._hitPoints;
	this->_energyPoints	= player._energyPoints;
	this->_attackDamage	= player._attackDamage;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &player)
{
	std::cout << "DiamondTrap assignement assignment operator called" << std::endl;
	if(this != &player) {
		ClapTrap::operator=(player);
		this->_name = player._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &healthP)
{
	if(this->_hitPoints < 1)
	{
		std::cout << "DiamondTrap " << this->_name << " esta mas que muerto" << std::endl;
		return;
	}
	if(this->_energyPoints < 1)
	{
		std::cout << "DiamondTrap " << this->_name << " con esos pocos puntos no vas a ningun sitio" << std::endl;
		return;
	}
	ScavTrap::attack(healthP);
}

void	DiamondTrap::whoAmI()
{
	if(this->_hitPoints < 1)
	{
		std::cout << "DiamondTrap " << this->_name << " esta MUERTO, no puede recordar quien es" << std::endl;
		return;
	}
	if (this->_energyPoints < 1)
	{
		std::cout << "DiamondTrap " << this->_name << " no tiene energia para recordar quien es" << std::endl;
		return;
	}
	std::cout << "Mi nombre de DiamondTrap es: " << this->_name << std::endl;
	std::cout << "Mi nombre de ClapTrap es: " << ClapTrap::_name << std::endl;
}
