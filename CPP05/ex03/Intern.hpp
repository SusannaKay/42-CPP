#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {

	public:

	Intern();
	Intern(Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	AForm *makeForm(std::string name, std::string target);

	class UnknownException : public std::exception{
		virtual const char *what() const throw();
	};

};



#endif