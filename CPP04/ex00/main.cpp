#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << "========== BASIC TEST ==========" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "Type j: " << j->getType() << std::endl;
	std::cout << "Type i: " << i->getType() << std::endl;
	std::cout << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;
	std::cout << "========== WRONG TEST ==========" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl;
	std::cout << "Type wrong_meta: " << wrong_meta->getType() << std::endl;
	std::cout << "Type wrong_cat: " << wrong_cat->getType() << std::endl;
	std::cout << std::endl;

	wrong_cat->makeSound();
	wrong_meta->makeSound();

	std::cout << std::endl;
	delete wrong_cat;
	delete wrong_meta;

	std::cout << std::endl;
	
	std::cout << "========== POLYMORPHISM ARRAY TEST ==========" << std::endl;
	const Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int i = 0; i < 4; i++)
	{
		std::cout << "animals[" << i << "] type: ";
		std::cout << animals[i]->getType() << " -> ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "========== END ==========" << std::endl;
	return (0);
}