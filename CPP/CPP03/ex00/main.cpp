#include "ClapTrap.hpp"

/*int main()
{
	int i = 0;
	ClapTrap user("Heri");
	ClapTrap boss("T-1000");
	ClapTrap final_boss("AFX");

	std::cout << std::endl << "---------- ATTACK ----------" << std::endl;
	std::cout << std::endl << "- Normal attack:" << std::endl;
	user.attack("AFX");
	std::cout << "\n- Attack without energy:" << std::endl;
	while(i < 3)
	{
		user.attack("AFX");
		i++;
	}
	std::cout << std::endl << "- Attack when dead:" << std::endl;
	user.takeDamage(15);
	user.attack("AFX");	

	std::cout << std::endl << "---------- DAMAGE ----------" << std::endl;
	std::cout << std::endl << "- Normal Damage:" << std::endl;
	final_boss.takeDamage(3);
	std::cout << std::endl << "- Damage > Hit:" << std::endl;
	final_boss.takeDamage(15);
	std::cout << std::endl << "- Dead ClapTrap:" << std::endl;
	final_boss.takeDamage(5);

	std::cout << std::endl << "---------- REPARE ----------" << std::endl;
	std::cout << std::endl << "- Normal Repare:" << std::endl;
	boss.beRepaired(5);
	std::cout << std::endl << "- Repair without energy:" << std::endl;
	i = 0;
	while(i < 3)
	{
		boss.beRepaired(1);
		i++;
	}
	std::cout << std::endl << "- Repair when dead:" << std::endl;
	boss.takeDamage(10);
    boss.beRepaired(5);
	
	std::cout << std::endl;

	return 0;
}*/

int	main(void)
{
	ClapTrap	user("user");
	ClapTrap	boss("T-1000");

	std::cout << "=====================================================" << std::endl;
	user.attack("T-1000");
	boss.takeDamage(5);
	boss.beRepaired(3);
	std::cout << "=====================================================" << std::endl;


	return 0;
}
