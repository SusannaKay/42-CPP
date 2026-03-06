/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:02:48 by skayed            #+#    #+#             */
/*   Updated: 2026/03/05 21:18:03 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_name = name, _hitPoints = 100 , _energyPoints = 50, _attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other){
	std::cout << "ScavTrap " << _name << " copy constructor has been called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other)
        {
			ClapTrap::operator=(other);
			std::cout << "ScavTrap " << _name << " operator= has been called" << std::endl;
		} 
    return *this;
}
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap" << _name << "destructor called\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;;
		return ;
	}
	else
		std::cout << "ScavTrap " << _name << " can't attack." << std::endl;
}