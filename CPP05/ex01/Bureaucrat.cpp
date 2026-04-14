#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		std::cout << "Default constructor called" << std::endl;
		_name = name;
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat &other)
	: _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Copy constructor called" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		std::cout << "Assignement operator called" << std::endl;
		_name = other.getName();
		_grade = other.getGrade();
	}
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}
int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::increment()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}
class GradeTooHighException : public std::exception
{
	virtual const char *what() const throw();
};
void Bureaucrat::signForm(Form &other)
{
	try
	{
		other.beSigned(*this);
		std::cout << _name << " signed " << other.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " couldn't sign " << other.getName() << " reason: " << e.what() << std::endl;
	}
}
std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (out);
}
