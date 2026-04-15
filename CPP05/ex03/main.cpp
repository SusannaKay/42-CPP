#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

Bureaucrat boss("Boss", 1);
Bureaucrat intern("Intern", 150);

std::cout << boss << std::endl;
std::cout << intern << std::endl;

std::cout << "\n=== SHRUBBERY ===" << std::endl;
    ShrubberyCreationForm shrub("home");

    intern.signForm(shrub);     // fail
    boss.signForm(shrub);       // ok

    intern.executeForm(shrub);  // fail
    boss.executeForm(shrub);    // ok

std::cout << "\n=== ROBOTOMY ===" << std::endl;

    RobotomyRequestForm robot("Bender");

    boss.signForm(robot);
    boss.executeForm(robot); 


std::cout << "\n=== PRESIDENTIAL PARDON ===" << std::endl;

    PresidentialPardonForm pardon("Marvin");

    intern.signForm(pardon);    // fail
    boss.signForm(pardon);      // ok

    intern.executeForm(pardon); // fail
    boss.executeForm(pardon);   // ok


std::cout << "\n=== TEST SENZA FIRMA ===" << std::endl;

    ShrubberyCreationForm test("error");

    boss.executeForm(test);


return 0;
}
