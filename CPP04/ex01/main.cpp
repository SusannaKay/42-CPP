#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	Cat *cesare = new Cat();

	cesare->setIdea("miao", 0);
	std::cout << cesare->getIdea(0) << std::endl;
	delete cesare;

	return 0;
}