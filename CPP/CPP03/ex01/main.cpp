#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	ct_user_1("HERIB9");
	ClapTrap	ct_boss("T-1000");
	ScavTrap	st_user_2("AFX");
	ScavTrap	st_boss("T-800");
	
	
	std::cout << "\n================= CLAPTRAP — NORMAL BEHAVIOR ================" << std::endl;
	ct_user_1.attack("T-1000");
	ct_boss.takeDamage(5);
	ct_boss.beRepaired(3);
	std::cout << "\n========== CLAPTRAP — DRAINING ENERGY (10 repairs) ==========" << std::endl;
	int i = 0;
	while (i < 10)
	{
		while(i < 9)
			i++;
		ct_user_1.beRepaired(10);
		i++;
	}
	ct_user_1.attack("T-1000");
	std::cout << "\n================= CLAPTRAP — DEATH SCENARIO =================" << std::endl;
	ct_boss.takeDamage(15);
	ct_boss.attack("HERIB9");
	ct_boss.beRepaired(5);
	std::cout << "\n================= SCAVTRAP — DRAINING ENERGY ================" << std::endl;
	st_user_2.attack("T-800");
	st_user_2.guardGate();	
	std::cout << "\n================= SCAVTRAP — DEATH SCENARIO =================" << std::endl;	
	st_boss.attack("AFX");	
	std::cout << std::endl;
	return 0;
}
