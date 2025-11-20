/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:42:48 by skayed            #+#    #+#             */
/*   Updated: 2025/11/20 14:16:03 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
	
	private:

	std::string name;
	Weapon& weapon;

	public:

	HumanA(std::string name, Weapon& w);
	~HumanA();
	void attack();
	
};

#endif