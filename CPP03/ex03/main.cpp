/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:06:30 by skayed            #+#    #+#             */
/*   Updated: 2026/03/14 14:44:46 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n--- Construction ---\n";
    DiamondTrap a("Alpha");

    std::cout << "\n--- Who am I ---\n";
    a.whoAmI();

    std::cout << "\n--- Attack ---\n";
    a.attack("target");

    std::cout << "\n--- Base abilities ---\n";
    a.takeDamage(20);
    a.beRepaired(10);

    std::cout << "\n--- Copy constructor ---\n";
    DiamondTrap b(a);
    b.whoAmI();
    b.attack("copy-target");

    std::cout << "\n--- Copy assignment ---\n";
    DiamondTrap c("Charlie");
    c = a;
    c.whoAmI();
    c.attack("assigned-target");

    std::cout << "\n--- End of program ---\n";
    return 0;
}