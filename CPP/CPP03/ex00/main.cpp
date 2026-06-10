#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	user("HERIB9");
	ClapTrap	boss("T-1000");

	std::cout << "\n================== NORMAL BEHAVIOR ===================" << std::endl;
	user.attack("T-1000");
	boss.takeDamage(5);
	std::cout << "\n================== DRAINING ENERGY ===================" << std::endl;
	std::cout << "T-1000 tiene: " << boss.getHitPoints() << " puntos de vida" << std::endl;
	boss.beRepaired(3);
	std::cout << "T-1000 tiene: " << boss.getHitPoints() << " puntos de vida" << std::endl;
	std::cout << "HERIB9 tiene: " << user.getEnergyPoints() << " puntos de energia" << std::endl;
	user.beRepaired(5);
	std::cout << "\n=================== OUT OF ENERGY ====================" << std::endl;
	user.attack("T-1000");
	boss.takeDamage(15);
	boss.attack("HERIB9");
	boss.beRepaired(5);
	std::cout << std::endl;

	return 0;
}
