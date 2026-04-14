#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class	Bureaucrat;

class Form
{
  private:
	std::string const _name;
	int const _grade;
	int const _exec;
	bool _isSigned;

  public:
	Form(std::string name, int grade, int exec);
	Form(Form &other);
	Form &operator=(const Form &other);
	~Form();
	std::string getName() const;
	int getGrade() const;
	bool getSigned() const;
	int getExec() const;

	void beSigned(Bureaucrat &other);

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &out, Form const &obj);
#endif