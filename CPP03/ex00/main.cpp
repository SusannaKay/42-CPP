/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:06:30 by skayed            #+#    #+#             */
/*   Updated: 2026/03/14 14:29:43 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap giorgio("Giorgio");

	std::cout << "TEST ATTACK FUNCTION:" << std::endl;
	giorgio.attack("Manuel");
	std::cout << "Energy points left:" << giorgio.getEnergy() << std::endl;

	std::cout << "TEST TAKE DAMAGE FUNCTION:" << std::endl;
	std::cout << "Hit points: " << giorgio.getHit() << std::endl;
	giorgio.takeDamage(9);
	std::cout << "Hit points: " << giorgio.getHit() << std::endl;

	std::cout << "TEST REPAIR FUNCTION:" << std::endl;
	std::cout << "Hit points: " << giorgio.getHit() << std::endl;
	std::cout << "Energy points: " << giorgio.getEnergy() << std::endl;
	giorgio.beRepaired(9);
	std::cout << "Hit points: " << giorgio.getHit() << std::endl;
	std::cout << "Energy points: " << giorgio.getEnergy() << std::endl;

	std::cout << "TEST ATTACK FUNCTION/ENERGY POINTS:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		giorgio.attack("Manuel");
	}
	giorgio.beRepaired(9);
}