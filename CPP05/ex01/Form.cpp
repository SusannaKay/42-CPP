#include "Form.hpp"

Form::Form(std::string name, int grade)
	: _name(name), _grade(grade)
{
	_isSigned = false;
}

Form::Form(Form &other)
	: _name(other._name), _grade(other._grade), _isSigned(other._isSigned){
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_name = other.getName();
		_grade = other.getGrade();
		_isSigned = other.getSigned();
	}
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

int Form::getGrade() const
{
	return (_grade);
}

bool Form::getSigned() const{
	return (_isSigned);
}

void Form::beSigned(Bureaucrat &other){
	if (other.getGrade() >= _grade)
		_isSigned = true;
	else
		Form::GradeTooLowException();
}