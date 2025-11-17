/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:02:56 by skayed            #+#    #+#             */
/*   Updated: 2025/10/08 11:08:26 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int j = 1; j < argc; j++)
		{
			std::string str = argv[j];
			for (unsigned long i = 0; i < str.length(); i++)
			{
				str[i] = std::toupper(str[i]);
				std::cout << str[i];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
