/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:06:30 by skayed            #+#    #+#             */
/*   Updated: 2026/03/05 21:20:53 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

static void print_state(const ScavTrap& s)
{
    std::cout << "Name=" << s.getName()
              << " HP=" << s.getHit()
              << " EN=" << s.getEnergy()
              << " ATK=" << s.getAttack()
              << "\n";
}

int main()
{
    std::cout << "\n--- Basic actions ---\n";
    ScavTrap a("Carlotta");
    print_state(a);

    a.guardGate();
    a.attack("Susanna");
    a.takeDamage(10);
    a.beRepaired(5);
    print_state(a);

    std::cout << "\n--- Copy constructor ---\n";
    ScavTrap c(a);
    c.attack("copy-target");
    print_state(c);
    print_state(a); 
	
    std::cout << "\n--- Copy assignment ---\n";
    ScavTrap b("B");
    b = a;
    b.attack("assigned-target");
    print_state(b);

    std::cout << "\n--- Dead check (HP=0) ---\n";
    ScavTrap d("D");
    d.takeDamage(200);   
    d.attack("nope");
    d.beRepaired(10);
    print_state(d);

    return 0;
}