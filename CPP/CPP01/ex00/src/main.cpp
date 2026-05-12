#include "../inc/Zombie.hpp"

int	main()
{
	std::cout << "\n==== ZOMBIE CREATED IN HEAP ====" << std::endl;
	Zombie *heapZombie0 = newZombie("Nemesis");
	heapZombie0->announce();
	std::cout << std::endl;
	Zombie *heapZombie1 = newZombie("Terminator");
	heapZombie1->announce();
	std::cout << std::endl;

	std::cout << "\n==== ZOMBIE CREATED IN STACK====" << std::endl;
	randomChump("stackNemesis");
	randomChump("stackTerminator");
	
	std::cout << "\n==== DESTROID ZOMBIE CREATED IN HEAP ====" << std::endl;
	delete heapZombie0;
	delete heapZombie1;

	std::cout << "\n==== END PROGRAM ====" << std::endl;
	
	return(0);
}