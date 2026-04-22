#include "AForm.hpp"

AForm::AForm(std::string name, int const grade, int const exec)
	: _name(name), _grade(grade), _exec(exec), _isSigned(false)
{
	if (_grade > 150 || _exec > 150)
		throw AForm::GradeTooLowException();
	else if (_grade < 1 || _exec < 1)
		throw AForm::GradeTooHighException();
	else
	{
		std::cout << "Form " << _name << " default constructor called" << std::endl;
	}
}

AForm::AForm(AForm &other)
	: _name(other._name), _grade(other._grade), _exec(other.getExec()),
		_isSigned(other._isSigned)
{
	std::cout << "Form " << _name << " Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
	{
		std::cout << "Form " << _name << " Assignement operator called" << std::endl;
		return (*this);
	}
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form " << _name << " destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return (_name);
}

int AForm::getGrade() const
{
	return (_grade);
}

int AForm::getExec() const
{
	return (_exec);
}

bool AForm::getSigned() const
{
	return (_isSigned);
}

void AForm::beSigned(Bureaucrat &other)
{
	if (other.getGrade() <= _grade)
	{
		_isSigned = true;
	}
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const{
	
	if (!_isSigned)
		throw FormNotSigned();
	if (executor.getGrade() > _exec)
		throw GradeTooLowException();
	executeAction();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Form not signed.");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

std::ostream &operator<<(std::ostream &out, AForm const &obj)
{
	out << "Form " << obj.getName() << ", grade: " << obj.getGrade() << ", execution grade: " << obj.getExec() << ", is signed: " << (obj.getSigned() ? "True" : "False") << std::endl;

	return (out);
}