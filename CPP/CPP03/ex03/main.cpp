#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	user("HERIB9");
	ClapTrap	boss("T-1000");
	ScavTrap	finalBoss("AFX");
	FragTrap	user2("TONIOEZU");
	
	std::cout << "=====================================================" << std::endl;
	user.attack("T-1000");
	boss.takeDamage(5);
	boss.beRepaired(3);
	finalBoss.attack("Heri");
	finalBoss.guardGate();
	user2.highFivesGuys();
	
	std::cout << "=====================================================" << std::endl;

	return 0;
}