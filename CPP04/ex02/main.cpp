#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
Cat a;

a.setIdea("fish", 0);

Cat b = a;

b.setIdea("pizza", 0);

std::cout << a.getIdea(0) << std::endl;
std::cout << b.getIdea(0) << std::endl;
}