#pragma once
#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &copy);
		~Cat();
		
		Cat &operator=(const Cat &copy);

		virtual void makeSound(void) const;
};
