#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm(target, 25, 5)
{
	std::cout << "Presidential Pardon Form " << target << " constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other)
	: AForm(other)
{
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
	std::cout << "Presidential Pardon Form " << getName() << " destructor called." << std::endl;
}

void PresidentialPardonForm::executeAction(std::string target) const
{
	std::cout << target << "has been pardoned by Zaphod Beeblebrox.\n";
}