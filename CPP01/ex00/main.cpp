/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:11:29 by skayed            #+#    #+#             */
/*   Updated: 2025/11/17 13:36:57 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main()
{
	Zombie zombie("Carlotta");
	Zombie *heapZombie;

	zombie.Announce();
	randomChump("Polpetta");
	heapZombie = newZombie("heapCarlotta");
	delete heapZombie;
	return (0);
}