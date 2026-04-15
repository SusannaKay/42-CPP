#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp";

class Intern {


	public:
	Intern();
	Intern(Intern &other);
	Intern &operator=(Intern &other);
	~Intern();
	
	AForm *makeForm(std::string formName, std::string target);
};



#endif