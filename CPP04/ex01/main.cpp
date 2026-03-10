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
	std::cout << "========== STACK OBJECTS TEST ==========" << std::endl;
	Animal	a;
	Dog		d;
	Cat		c;

	std::cout << a.getType() << std::endl;
	std::cout << d.getType() << std::endl;
	std::cout << c.getType() << std::endl;

	a.makeSound();
	d.makeSound();
	c.makeSound();

	std::cout << std::endl;
	std::cout << "========== COPY CONSTRUCTOR TEST ==========" << std::endl;
	Dog	dog1;
	Dog	dog2(dog1);

	std::cout << "dog1 type: " << dog1.getType() << std::endl;
	std::cout << "dog2 type: " << dog2.getType() << std::endl;
	dog2.makeSound();

	std::cout << std::endl;
	std::cout << "========== ASSIGNMENT TEST ==========" << std::endl;
	Cat	cat1;
	Cat	cat2;

	cat2 = cat1;
	std::cout << "cat1 type: " << cat1.getType() << std::endl;
	std::cout << "cat2 type: " << cat2.getType() << std::endl;
	cat2.makeSound();

	std::cout << std::endl;
	std::cout << "========== POLYMORPHISM ARRAY TEST ==========" << std::endl;
	const Animal* animals[4];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();

	for (int idx = 0; idx < 4; idx++)
	{
		std::cout << "animals[" << idx << "] type: ";
		std::cout << animals[idx]->getType() << " -> ";
		animals[idx]->makeSound();
	}

	for (int idx = 0; idx < 4; idx++)
		delete animals[idx];

	std::cout << std::endl;
	std::cout << "========== END ==========" << std::endl;
	return (0);
}