#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
	private:
		 std::string const _name;
		bool _isSigned;
		 int const _grade;

	public:
		Form(std::string name, int grade);
		Form(Form &other);
		Form &operator=(const Form &other);
		std::string getName() const;
		int getGrade() const;
		bool getSigned() const;
		

		void beSigned(Bureaucrat &other);


	class GradeTooHighException : public std::exception{
		virtual const char *what() const throw();
		};
	class GradeTooLowException : public std::exception{
		virtual const char *what() const throw();
		};
	std::ostream &operator<<(std::ostream &out);
};


#endif