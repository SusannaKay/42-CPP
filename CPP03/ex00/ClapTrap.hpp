/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:07:13 by skayed            #+#    #+#             */
/*   Updated: 2026/03/04 14:15:14 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
class ClapTrap
{
  private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

  public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &other);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void setHit(int n);
	void setEnergy(int n);
	void setAttack(int n);
	std::string getName();
	unsigned int getHit();
	unsigned int getEnergy();
	unsigned int getAttack();
};

#endif