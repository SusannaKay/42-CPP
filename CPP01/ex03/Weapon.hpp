/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:12:13 by skayed            #+#    #+#             */
/*   Updated: 2025/11/20 14:17:34 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon{
	private:
	
	std::string type;

	public:
	
	Weapon(std::string str);
	~Weapon();
	const std::string& getType() const;
	void setType(std::string str);
};

#endif