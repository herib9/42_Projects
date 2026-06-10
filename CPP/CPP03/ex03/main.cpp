#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	user("HERIB9");
	ClapTrap	boss("T-1000");
	ScavTrap	finalBoss("AFX");
	FragTrap	user2("TONIOEZU");
	DiamondTrap	user3("BONITO_DE_CARA");
	
	std::cout << "=================================================================" << std::endl;
	std::cout << std::endl;
	user3.attack("HERIB9");
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
	std::cout << std::endl;
	finalBoss.attack("BONITO_DE_CARA");
	finalBoss.attack("BONITO_DE_CARA");
	finalBoss.attack("BONITO_DE_CARA");
	finalBoss.attack("BONITO_DE_CARA");
	finalBoss.attack("BONITO_DE_CARA");
	std::cout << std::endl;
	user3.takeDamage(99);
	user3.attack("HERIB9");
	user3.takeDamage(1);
	user3.attack("HERIB9");
	std::cout << "=================================================================" << std::endl;
	std::cout << std::endl;
	return 0;
}



/*
Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
• attack() (ScavTrap)
*/