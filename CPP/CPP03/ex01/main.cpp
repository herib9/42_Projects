#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	user("HERIB9");
	ClapTrap	boss("T-1000");
	ScavTrap	finalBoss("AFX");
	
	
	std::cout << "=====================================================" << std::endl;
	user.attack("T-1000");
	std::cout << std::endl;
	boss.takeDamage(5);
	boss.beRepaired(3);
	int i = 0;
	while (i < 10)
	{
		user.attack("T-1000");
		i++;
	}
	user.attack("T-1000");
	user.beRepaired(5);
	std::cout << std::endl;
	finalBoss.attack("Heri");
	finalBoss.guardGate();
	std::cout << "=====================================================" << std::endl;

	return 0;
}
