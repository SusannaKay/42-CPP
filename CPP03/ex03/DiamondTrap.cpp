/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:52:34 by skayed            #+#    #+#             */
/*   Updated: 2026/03/05 22:57:56 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name){
	_name = ClapTrap._name + "clap_name";
}
DiamondTrap::DiamondTrap(const DiamondTrap &other);
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other);
DiamondTrap::~DiamondTrap();
void DiamondTrap::whoAmI();