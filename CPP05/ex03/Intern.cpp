#include "Intern.hpp"

	Intern::Intern(){
		std::cout << "Intern constructor called\n";
	}
	Intern::Intern(Intern &other){
		if(this != &other){}
		std::cout << "Intern copy constructor called\n";

	}
	Intern &Intern::operator=(Intern &other){
		if(this != &other)
		{}

		std::cout << "Intern operator assignement constructor called\n";
		return (*this);
	}
	Intern::~Intern(){
		std::cout << "Intern destructor called\n";
	}
	
	AForm *Intern::makeForm(std::string formName, std::string target){

		AForm *form;
		
	}