#include "Cat.hpp"

Cat::Cat() : ideas(new(Brain))
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), Brain(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
		{
			this->type = other.type;
			this->ideas = other.ideas;
		}
	return (*this);
}

Cat::~Cat()
{
	delete Brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}

void	Cat::setidea(std::string idea, int i){
	if (i < 0 || i >= 100)
		std::cout << "Index out of range" << std::endl;
	ideas[i] = idea;
}

std::string Cat::getIdea(int i){
		if (i < 0 || i >= 100)
		std::cout << "Index out of range" << std::endl;
	return (ideas[i]);
}