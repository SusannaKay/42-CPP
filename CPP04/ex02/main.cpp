#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
Cat a;
//Animal c;

a.setIdea("fish", 0);

Dog b;

b.makeSound();
a.makeSound();

std::cout << a.getIdea(0) << std::endl;
std::cout << b.getIdea(0) << std::endl;
}