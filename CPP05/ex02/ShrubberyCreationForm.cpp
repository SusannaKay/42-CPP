#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137){
	_target = "Corinne";
	std::cout << "Shrubbery Creation form " << _target << " constructor called." << std::endl;

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery Creation", 145, 137)
{
	_target = target;
	std::cout << "Shrubbery Creation form " << _target << " constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
	: AForm(other)
{
	_target = other.getTarget();
	std::cout << "Shrubbery Creation form " << _target << " copy constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		_target = other.getTarget();
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation form " << _target << " destructor called." << std::endl;
}
void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Couldn't create the target file\n";
		return;
	}
	file << "      /\\/\\\n     /\\O\\*\\\n    /*/\\/\\/\\\n   /\\O\\/\\*\\/\\\n  /\\*\\/\\*\\/\\/\\\n /\\O\\/\\/*/\\/O/\\\n      ||\n      ||\n";

	file.close();
}

std::string ShrubberyCreationForm::getTarget() const{
	return (_target);
}