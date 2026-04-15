#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Form", 25, 5)
{
	_target = "Carlotta";
	std::cout << "Presidential Pardon Form " << _target << " constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("Presidential Form", 25, 5)
{
	_target = target;
	std::cout << "Presidential Pardon Form " << target << " constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
	: AForm(other)
{
	_target = other.getTarget();
	std::cout << "Presidential Pardon Form " << other.getName() << " copy constructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form " << _target << " destructor called." << std::endl;
}

void PresidentialPardonForm::executeAction(std::string target) const
{
	std::cout << target << "has been pardoned by Zaphod Beeblebrox.\n";
}

std::string PresidentialPardonForm::getTarget() const {
	return(_target);
}