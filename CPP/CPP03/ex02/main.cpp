#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

/* int	main(void)
{
	ClapTrap	user("HERIB9");
	ClapTrap	boss("T-1000");
	ScavTrap	finalBoss("AFX");
	FragTrap	user2("TONIOEZU");
	
	std::cout << "======================================================" << std::endl;
	user.attack("T-1000");
	std::cout << std::endl;
	boss.takeDamage(5);
	boss.beRepaired(3);
	std::cout << std::endl;
	finalBoss.attack("HERIB9");
	finalBoss.guardGate();
	std::cout << std::endl;
	user2.highFivesGuys();
	std::cout << "======================================================" << std::endl;

	return 0;
} */

int main(void)
{
	ClapTrap	ct("HERIB9");
	ScavTrap	st("AFX");
	FragTrap	ft("TONIOEZU");	

	std::cout << "\n======= CLAPTRAP — NORMAL BEHAVIOR =======" << std::endl;
	ct.attack("AFX");
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << "\n======= CLAPTRAP — DEATH SCENARIO =======" << std::endl;
	ct.takeDamage(20);
	ct.attack("AFX");
	ct.beRepaired(5);

	std::cout << "\n======= SCAVTRAP — NORMAL BEHAVIOR =======" << std::endl;
	st.attack("HERIB9");
	st.guardGate();

	std::cout << "\n======= SCAVTRAP — DEATH SCENARIO =======" << std::endl;
	st.takeDamage(120);
	st.attack("HERIB9");

	std::cout << "\n======= FRAGTRAP — NORMAL BEHAVIOR =======" << std::endl;
	ft.attack("HERIB9");
	ft.highFivesGuys();

	std::cout << "\n======= FRAGTRAP — DEATH SCENARIO =======" << std::endl;
	ft.takeDamage(120);
	ft.attack("HERIB9");	
	std::cout << std::endl;
	
	return 0;
}