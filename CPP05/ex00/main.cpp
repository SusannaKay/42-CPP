#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat tom("Tom", 150);
	Bureaucrat betty("Betty", 1);

	std::cout << tom << std::endl;

	try
	{
		tom.decrement();
		std::cout << tom << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

		try
	{
		tom.increment();
		std::cout << tom << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << betty << std::endl;
	try
	{
		betty.increment();
	}
	catch (std::exception &d)
	{
		std::cout << d.what() << std::endl;
	}

	try
	{
		betty.decrement();
		std::cout << betty << std::endl;
	}

	catch (std::exception &d)
	{
		std::cout << d.what() << std::endl;
	}
}