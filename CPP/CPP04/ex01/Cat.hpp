#pragma once
#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		Cat &operator=(const Cat &copy);
		~Cat();

		virtual void makeSound(void) const;
};
