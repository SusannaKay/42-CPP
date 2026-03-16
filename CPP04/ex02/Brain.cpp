#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other){
	if (this != &other)
	{		
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignement operator called" << std::endl;
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain destructor called." << std::endl;
}
void Brain::setIdea(const std::string& idea, int i)
{
	if (i >= 0 && i < 100)
		ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return ideas[i];
	return "";
}