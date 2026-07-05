#pragma once
#include <string>
#include <iostream>

class AAnimal
{
	protected:
		std::string	_type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();
		
		AAnimal &operator=(const AAnimal &copy);

		const	std::string &getType(void) const;
		virtual void makeSound(void) const = 0;
};
