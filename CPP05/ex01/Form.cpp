#include "Form.hpp"

Form::Form(std::string name, int const grade) : _name(name), _grade(grade), _isSigned(false)
{
	if (_grade > 150)
		throw Form::GradeTooLowException();
	else if (_grade < 1)
		throw Form::GradeTooHighException();
	else
	{
		std::cout << "Form " << _name << " default constructor called" << std::endl;
	}
}

Form::Form(Form & other)
		: _name(other._name), _grade(other._grade), _isSigned(other._isSigned)
{
		std::cout << "Form " << _name << " Copy constructor called" << std::endl;
	}

Form &Form::operator=(const Form &other)
	{
		if (this == &other)
		{
			std::cout << "Form " << _name << " Assignement operator called" << std::endl;
			return (*this);
		}
		return (*this);
	}

Form::~Form()
	{
		std::cout << "Form " << _name << " destructor called" << std::endl;
	}

std::string Form::getName() const
	{
		return (_name);
	}

int Form::getGrade() const
	{
		return (_grade);
	}

bool Form::getSigned() const
	{
		return (_isSigned);
	}

void Form::beSigned(Bureaucrat & other)
	{
		if (other.getGrade() <= _grade)
		{
			_isSigned = true;
		}
		else
			throw Form::GradeTooLowException();
	}

const char *Form::GradeTooLowException::what() const throw()
	{
		return ("Grade too low.");
	}

const char *Form::GradeTooHighException::what() const throw()
	{
		return ("Grade too high.");
	}

std::ostream &operator<<(std::ostream &out, Form const &obj)
	{
		out << "Form " << obj.getName() << ", grade " << obj.getGrade() << ",is signed : " << obj.getSigned();
		return (out);
	}