#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat tom("Tom", 40);
	Bureaucrat betty("Betty", 1);

	Form one("One", 30);


	std::cout << tom << std::endl;
	std::cout << one << std::endl;
	try
	{
		tom.signForm(one);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << betty << std::endl;
	try
	{
		betty.signForm(one);
	}
	catch (std::exception &d)
	{
		std::cout << d.what() << std::endl;
	}
}