#include "Brain.hpp"

Brain::Brain(){

	ideas = {0};
	std::cout << "Brain default constructor called" << std::endl;
}
Bran::Brain(const Brain &other){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}
Brain &Bran::operator=(const Brain &other){
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0, i < 100, i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}
Bran::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}