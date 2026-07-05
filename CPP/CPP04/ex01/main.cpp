#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main ()
{
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	delete d;
	delete c;
	std::cout << std::endl;
	
	std::cout << "CREACION DE ARRAYS DE ANIMALS" << std::endl;
	const Animal *animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog;
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat;
	std::cout << std::endl;

	std::cout << "DESTRUCCION DE ARRAYS DE ANIMALS" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];
	std::cout << std::endl;

	std::cout << "DEEP COPY DOG" << std::endl;
	Dog d1;
	d1.getBrain()->setIdea(0, "FUCKING HIPPIES");
	Dog d2 = d1;
	d2.getBrain()->setIdea(0, "I LOVE YOUR MAGIC POISON");
	std::cout << "*** BRAIN dog_1: " << d1.getBrain()->getIdea(0) << std::endl;
	std::cout << "*** BRAIN dog_2: " << d2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "DEEP COPY CAT" << std::endl;
	Cat c1;
	c1.getBrain()->setIdea(0, "RONRRONEO ELEVADOR DE ALMAS");
	Cat c2 = c1;
	c2.getBrain()->setIdea(0, "MUSIC FOR THE PEOPLE");
	std::cout << "+++ BRAIN cat_1: " << c1.getBrain()->getIdea(0) << std::endl;
	std::cout << "+++ BRAIN cat_2: " << c2.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	return 0;
}
