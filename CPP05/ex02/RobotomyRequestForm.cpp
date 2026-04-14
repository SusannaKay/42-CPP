#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(target, 72, 45)
{
	std::cout << "Robotomy Request Form " << target << " constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
	: AForm(other)
{
	std::cout << "Robotomy Request Form " << other.getName() << " copy constructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form " << getName() << " destructor called." << std::endl;
}

void RobotomyRequestForm::Robotomy(std::string target){

	int num = rand();
	
	std::cout << "BzzzZZzzz\nBzZZzzzz\nbzZzzzZz\n." ;
	if (num % 2 == 0)
		std::cout << target << " robotomized successfully.\n";
	else
		std::cout << target << " robotomy failed.\n";
}