#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	user("HERIB9");
	ClapTrap	boss("T-1000");

	std::cout << "\n================== NORMAL BEHAVIOR ===================" << std::endl;
	user.attack("T-1000");
	//std::cout << std::endl;
	boss.takeDamage(5);
	std::cout << "T-1000 tiene: " << boss.getHitPoints() << " health points" << std::endl;
	boss.beRepaired(3);
	std::cout << "\n============ DRAINING ENERGY (10 repairs) ============" << std::endl;
	std::cout << "HERIB9 tiene: " << user.getEnergyPoints() << " energy points" << std::endl;
	int i = 0;
	while (i < 8)
	{
		while (i < 7)
			i++;
		user.beRepaired(10);
		i++;
	}
	std::cout << "\n=================== OUT OF ENERGY ====================" << std::endl;
	user.attack("T-1000");
	user.beRepaired(5);
	boss.takeDamage(15);
	boss.attack("HERIB9");
	boss.beRepaired(5);
	std::cout << std::endl;

	return 0;
}
