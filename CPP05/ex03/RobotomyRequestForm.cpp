#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45)
{
	_target = "Pipa";
	std::cout << "Robotomy Request Form " << _target << " constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Robotomy Request", 72, 45)
{
	_target = target;
	std::cout << "Robotomy Request Form " << target << " constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other)
	: AForm(other)
{
	_target = other.getTarget();
	std::cout << "Robotomy Request Form " << other.getTarget() << " copy constructor called." << std::endl;
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
	std::cout << "Robotomy Request Form " << _target << " destructor called." << std::endl;
}

void RobotomyRequestForm::executeAction(std::string target) const{

	int num = rand();
	
	std::cout << "BzzzZZzzz\nBzZZzzzz\nbzZzzzZz\n" ;
	if (num % 2 == 0)
		std::cout << target << " robotomized successfully.\n";
	else
		std::cout << target << " robotomy failed.\n";
}

std::string RobotomyRequestForm::getTarget() const {
	return (_target);
}