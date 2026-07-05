#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main ()
{
	const AAnimal* d = new Dog();
	const AAnimal* c = new Cat();
	std::cout << "\nPara comprobar la clase abstracta modifica el main...\n" << std::endl;
	//const AAnimal *f = new AAnimal();
	delete d;
	delete c;
	std::cout << std::endl;
	return 0;
}
