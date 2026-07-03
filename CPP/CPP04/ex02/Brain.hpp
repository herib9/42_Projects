#pragma once
#include <string>
#include <iostream>

class	Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain &operator=(const Brain &copy);

		const	std::string &getIdea(int index) const;
		void	setIdea(int index, const std::string &idea);
};