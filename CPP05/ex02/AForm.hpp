#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class	Bureaucrat;

class AForm
{
	private:

	std::string const _name;
	int const _grade;
	int const _exec;
	bool _isSigned;

	protected:

	virtual void executeAction() const = 0;

	public:
	
	AForm(std::string name, int grade, int exec);
	AForm(AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm() = 0;
	std::string getName() const;
	int getGrade() const;
	bool getSigned() const;
	int getExec() const;

	virtual void beSigned(Bureaucrat &other);
	void execute(Bureaucrat const &executor) const;
	

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		virtual const char *what() const throw();
	};

};
std::ostream &operator<<(std::ostream &out, AForm const &obj);
#endif