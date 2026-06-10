#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("defConsTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0), _silent(false)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _silent(false)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &player) : _name(player._name), _hitPoints(player._hitPoints), _energyPoints(player._energyPoints), _attackDamage(player._attackDamage), _silent(player._silent)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &player)
{
	std::cout << "Assignement operator called" << std::endl;
	if(this != &player)
	{
		this->_name 			= player._name;
		this->_hitPoints 		= player._hitPoints;
		this->_energyPoints 	= player._energyPoints;
		this->_attackDamage 	= player._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if(this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " MUERTO! no puede atacar, no tiene puntos de vida" << std::endl;
		return;
	}
	else if (this->_energyPoints < 1) 
	{
	std::cout <<  "ClapTrap " << this->_name << " no puede atacar, no tiene puntos de energia" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " ataca " << target << std::endl;
}

void	ClapTrap::takeDamage(unsigned int damageP)
{
	this->_hitPoints -= (int)damageP;
	if(this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " recibe " << damageP << " puntos de daño" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int healthP)
{
	if (this->_hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->_name << " MUERTO! no se puede curar, no tiene puntos de vida" << std::endl;
		return ;
	}
	else if (this->_energyPoints < 1)
	{
		if(_silent == false)
			std::cout << "ClapTrap " << this->_name << " no se puede curar, no tiene puntos de energia" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += healthP;
	if(_silent == false)
		std::cout << "ClapTrap " << this->_name << " se ha curado " << healthP << " puntos de vida" << std::endl;
}

int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}
