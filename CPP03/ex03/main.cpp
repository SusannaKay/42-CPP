/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:06:30 by skayed            #+#    #+#             */
/*   Updated: 2026/03/05 22:28:25 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    std::cout << "\n--- Construction test ---\n";
    FragTrap a("Alpha");

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
    return 0;
}