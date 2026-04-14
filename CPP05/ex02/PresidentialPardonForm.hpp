#ifndef PRESIDENTIAL_PARDON_HPP
# define PRESIDENTIAL_PARDON_HPP

# include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
  public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	void Pardon(std::string target);
};

#endif