/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:06:30 by skayed            #+#    #+#             */
/*   Updated: 2026/03/14 14:39:05 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "\n--- Construction test ---\n";
	FragTrap a("Alpha");
	std::cout << "Alpha HitPoints: " << a.getHit() << std::endl;
	std::cout << "Alpha EnergyPoints: " << a.getEnergy() << std::endl;
	std::cout << "Alpha Attack Damage: " << a.getAttack() << std::endl;

	std::cout << "\n--- Basic actions ---\n";
	a.attack("target");
	a.highFivesGuys();

	std::cout << "\n--- Copy constructor ---\n";
	FragTrap b(a);
	b.attack("enemy");

	std::cout << "\n--- Copy assignment ---\n";
	FragTrap c("Charlie");
	c = a;
	c.attack("another target");

	std::cout << "\n--- End of program ---\n";
	return (0);
}