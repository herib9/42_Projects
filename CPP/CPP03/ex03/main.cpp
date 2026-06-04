#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	ClapTrap	user("HERIB9");
	ClapTrap	boss("T-1000");
	ScavTrap	finalBoss("AFX");
	FragTrap	user2("TONIOEZU");
	DiamondTrap	user3("BONITO");
	
	std::cout << "=================================================================" << std::endl;
	user.attack("T-1000");
	std::cout << std::endl;
	boss.takeDamage(5);
	boss.beRepaired(3);
	std::cout << std::endl;
	finalBoss.attack("Heri");
	finalBoss.guardGate();
	std::cout << std::endl;
	user2.attack("HERIB9");
	user2.highFivesGuys();
	std::cout << std::endl;
	user3.whoAmI();
	user3.attack("HERIB9");
	std::cout << "=================================================================" << std::endl;

	return 0;
}