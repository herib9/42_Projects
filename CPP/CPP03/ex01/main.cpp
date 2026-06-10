#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	ct_user_1("HERIB9");
	ClapTrap	ct_boss("T-1000");

	ScavTrap	st_user_2("AFX");
	ScavTrap	st_boss("T-800");
	
	std::cout << "\n================= CLAPTRAP ================" << std::endl;
	ct_user_1.attack("T-1000");
	ct_boss.takeDamage(5);
	ct_boss.beRepaired(3);
	ct_user_1.beRepaired(10);
	ct_user_1.attack("T-800");
	st_boss.takeDamage(20);
	ct_boss.attack("HERIB9");
	ct_boss.beRepaired(5);
	std::cout << "HERIB9 tiene: " << ct_user_1.getEnergyPoints() << " puntos de energia" << std::endl;
	std::cout << "\n================= SCAVTRAP ================" << std::endl;
	st_user_2.attack("T-800");
	st_user_2.guardGate();	
	st_boss.attack("AFX");
	st_user_2.takeDamage(100);
	st_user_2.attack("T-800");
	st_user_2.beRepaired(5);
	
	std::cout << std::endl;
	return 0;
}
