#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain *_brain;

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &copy);
		~Dog();

		Dog &operator=(const Dog &copy);

		virtual void makeSound(void) const;
		Brain *getBrain(void) const;
};
