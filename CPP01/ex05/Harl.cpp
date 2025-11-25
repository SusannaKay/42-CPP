/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:14:36 by skayed            #+#    #+#             */
/*   Updated: 2025/11/25 14:32:29 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void Harl::complain(std::string level){

	std::string levels[4] = {
		"DEBUG",
		"INFO", 
		"WARNING", 
		"ERROR"
	};
	void (Harl::*actions[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
	{
		if ( level == levels[i])
		{
			(this ->* actions[i])();
			return;
		}
	}
	std::cout << "Command not found. Must be <DEBUG>, <INFO>, <WARNING> or <ERROR>" << std::endl ;
	return ;
}

void Harl::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}
void Harl::warning(){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error(){
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}