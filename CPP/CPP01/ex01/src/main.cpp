#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie	*newHorde = zombieHorde(5, "Horda Zombie");
	int	i = 0;

	while(i < 5)
	{
		newHorde[i].announce();
		i++;
	}
	std::cout << std::endl;
	delete[] newHorde;
}