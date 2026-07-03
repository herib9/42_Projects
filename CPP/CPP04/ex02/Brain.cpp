#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&Brain::operator=(const Brain &copy)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if(this != &copy)
	{
		int i = 0;
		while (i < 100)
		{
			this->_ideas[i] = copy._ideas[i];
			i++;
		}
	}
	return *this;
}

const std::string &Brain::getIdea(int index) const
{
	return this->_ideas[index];
}

void Brain::setIdea(int index, const std::string &idea)
{
	this->_ideas[index] = idea;
}