#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
	private:
		Brain *_brain;

	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		~Cat();

		Cat &operator=(const Cat &copy);

		virtual void makeSound(void) const;
		Brain *getBrain(void) const;
};
