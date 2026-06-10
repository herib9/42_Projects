#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("defConsScav")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
} 

ScavTrap::ScavTrap(const ScavTrap &target) : ClapTrap(target) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&ScavTrap::operator=(const ScavTrap &player) {
	std::cout << "ScavTrap assignement operator called" << std::endl;
	if(this != &player)
		ClapTrap::operator=(player);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if(this->_hitPoints < 1) {
		std::cout << "ScavTrap " << this->_name << " a MORIO! no puede atacar, no tiene puntos de vida" << std::endl;
		return ;
	}
	else if (this->_energyPoints < 1) {
	std::cout <<  "ScavTrap " << this->_name << " ENERGIA a 0, no puede atacar, no tiene puntos de energia" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " guantazo a " << target << " causando " << this->_attackDamage << " puntos de daño al oponente" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->_hitPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " no puede entrar en Gate keeper mode, no tiene puntos de vida" << std::endl;
		return;
	}
	if(this->_energyPoints < 1)
	{
		std::cout << "ScavTrap " << this->_name << " no tiene puntos de energia y no puede entrar en Gate keeper mode" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " ha entrado en Gate keeper mode" << std::endl;
}
