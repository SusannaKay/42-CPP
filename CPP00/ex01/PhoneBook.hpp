/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:56:26 by skayed            #+#    #+#             */
/*   Updated: 2025/11/10 11:45:03 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include "Contact.hpp"
#include <limits>

class PhoneBook
{
	private:
	
	Contact contacts[8];
	int index;
	int	count;


	public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();
	void displayContact(int index);
};

#endif