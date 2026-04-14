#include "ShrubberyCreationForm.hpp"

int main(void){

	ShrubberyCreationForm shrub("Shrubbery");
	
	shrub.CreateFile();
	std::cout << shrub;
}