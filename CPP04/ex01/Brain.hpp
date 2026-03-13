#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{

	public:

	std::string ideas[100];
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
	void	setIdea(const std::string &idea, int i);
	std::string	getIdea(int i) const;
};

#endif