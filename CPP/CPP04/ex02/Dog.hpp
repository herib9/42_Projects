#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal
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
