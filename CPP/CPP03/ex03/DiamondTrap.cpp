#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>

DiamondTrap::DiamondTrap() : ClapTrap("AUTECHRE_clap_name") {
	std::cout << "DiamondTrap" << std::string ClapTrap::_name << "default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap() : int FragTrap() {
	_hitPoints = 100;
}

