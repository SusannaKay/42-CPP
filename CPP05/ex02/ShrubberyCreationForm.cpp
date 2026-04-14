#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(target, 145, 137)
{
	std::cout << "Shrubbery Creation form " << target << " constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other)
	: AForm(other)
{
	std::cout << "Shrubbery Creation form " << other.getName() << " copy constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation form " << getName() << " destructor called." << std::endl;
}
void ShrubberyCreationForm::CreateFile(void)
{
	std::string filename = getName() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Couldn't create the target file\n";
		return;
	}
	file << "↟𖠰˚☀︎ᨒ↟𖠰\n";
	file.close();
}