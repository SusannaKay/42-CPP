#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"


class Bureaucrat
{
  private:
	std::string _name;
	int _grade;

  public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();


	std::string getName(void) const;
	int getGrade(void) const;
	void increment();
	void decrement();
	void signForm(Form &other);

	class GradeTooHighException : public std::exception{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
		virtual const char *what() const throw();
	};
};
	std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);
#endif

