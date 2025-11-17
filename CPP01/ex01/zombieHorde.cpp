/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:38:48 by skayed            #+#    #+#             */
/*   Updated: 2025/11/17 15:06:19 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	std::stringstream conv;
	Zombie *horde = new Zombie[N];
	std::string str;
	
	for (int i =0; i < N; i++)
	{
		conv << name << i;
		horde[i].setName(conv.str());
		conv.str("");
		conv.clear();
	}
	return horde;
}