#include "Intern.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

	Intern::Intern(){
		std::cout << "Intern constructor called\n";
	}
	Intern::Intern(Intern &other){
		if(this != &other){}
		std::cout << "Intern copy constructor called\n";

	}
	Intern &Intern::operator=(const Intern &other){
		if(this != &other)
		{}

		std::cout << "Intern operator assignement constructor called\n";
		return (*this);
	}
	Intern::~Intern(){
		std::cout << "Intern destructor called\n";
	}
	
	static AForm *createRobotomy(std::string target){
		return new RobotomyRequestForm(target);
	}
	static AForm *createShrubbery(std::string target){
		return new ShrubberyCreationForm(target);
	}
	static AForm *createPresidential(std::string target){
		return new PresidentialPardonForm(target);
	}

	AForm *Intern::makeForm(std::string name, std::string target){

		std::string forms[3] = {
			"robotomy request",
			"shrubbery creation",
			"presidential pardon",
		};
		AForm *(*creators[3])(std::string) = {
			createRobotomy,
			createShrubbery,
			createPresidential,
		};
		for (int i = 0; i < 3; i++)
		{
			if(name == forms[i])
				return creators[i](target);
		}
		throw UnknownException();
		
	}

	const char *Intern::UnknownException::what() const throw()
	{
		return ("Unknown Form Name");
	}