/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:11:29 by skayed            #+#    #+#             */
/*   Updated: 2025/11/25 17:04:36 by skayed           ###   ########.fr       */
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
	heapZombie->Announce();
	delete heapZombie;
	return (0);
}