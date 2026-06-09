#pragma once
#include <string>
#include <iostream>

class	WrongAnimal
{
	protected:
		std::string		_type;

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal &copy);
		~WrongAnimal();

		const std::string &getType(void) const;
		void makeSound(void) const;
};