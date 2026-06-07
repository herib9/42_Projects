#pragma once
#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		virtual ~Animal();

		const	std::string &getType(void) const;
		virtual void makeSound(void) const;
};
