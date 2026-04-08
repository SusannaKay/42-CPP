#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>


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

	class GradeTooHighException : public std::exception{
		virtual const char *what() const throw(){
			return ("Grade too high.");
		}
	};
	class GradeTooLowException : public std::exception{
		virtual const char *what() const throw(){
			return ("Grade too low.");
		}
		
	};
};
	std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);
#endif

