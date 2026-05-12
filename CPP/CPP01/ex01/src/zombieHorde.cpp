#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie	*newHorde = new Zombie[N];

	while(i < N)
	{
		newHorde[i].setName(name);
		i++;
	}
	return (newHorde);
}