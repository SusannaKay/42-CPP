/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:32:01 by skayed            #+#    #+#             */
/*   Updated: 2025/11/20 16:10:12 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB{
	
	private:

	std::string name;
	Weapon* weapon;

	public:

	HumanB(std::string str);
	~HumanB();
	void attack();
	void setWeapon(Weapon& w);
	
};

#endif