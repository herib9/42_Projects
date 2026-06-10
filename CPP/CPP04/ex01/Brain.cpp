#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&Brain::operator=(const Brain &copy)
{

}



const std::string Brain::getIdea(int index) const
{

}