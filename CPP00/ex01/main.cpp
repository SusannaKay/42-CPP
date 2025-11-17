/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:59:36 by skayed            #+#    #+#             */
/*   Updated: 2025/11/06 18:12:44 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int	main(void)
{
	PhoneBook	phonebook;
	std::string str;
	
	while (true)
	{
		
		std::cout << "Enter Command (you can use ADD, SEARCH or EXIT):" << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << "\nEOF detected. Exiting.\n";
			break ;
		}
		if (str == "ADD")
			phonebook.addContact();

		if (str == "SEARCH")
			phonebook.searchContact();
		if (str == "EXIT")
			break;
	}
	return (0);
}
