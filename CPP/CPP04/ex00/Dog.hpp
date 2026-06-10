#pragma once
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		~Dog();
		
		Dog &operator=(const Dog &copy);
		
		virtual void makeSound(void) const;
};