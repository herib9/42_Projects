#include "../inc/Weapon.hpp"
#include "../inc/HumanA.hpp"
#include "../inc/HumanB.hpp"
#include <iostream>

int main()
{
	std::cout << "\n--- Test HumanA con un arma ---" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "\n--- Test HumanB con un arma ---" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "\n--- Test HumanB con dos armas ---" << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        Weapon sword = Weapon("shiny golden sword");
        
        HumanB jim("Jim");
        jim.attack(); // Test: Ataca sin arma (dirá que no tiene)
        jim.setWeapon(club);
        jim.attack();
        
        std::cout << "...Jim encuentra algo mejor..." << std::endl;
        
        jim.setWeapon(sword); // CAMBIO: Ahora apunta a la espada
        jim.attack();
        sword.setType("broken golden sword"); // El cambio se refleja automáticamente
        jim.attack();
    }
	return 0;
}
