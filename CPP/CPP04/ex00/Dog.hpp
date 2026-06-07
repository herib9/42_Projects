#pragma once
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		~Dog();

		virtual void makeSound(void) const;
};