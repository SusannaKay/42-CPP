/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:39:50 by skayed            #+#    #+#             */
/*   Updated: 2026/03/05 17:41:03 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << this->_name << " constructor has been called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	this->_name = other.getName();
	this->_hitPoints = other.getHit();
	this->_energyPoints = other.getEnergy();
	this->_attackDamage = other.getAttack();
	std::cout << this->_name << " copy constructor has been called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		_name = other.getName();
		_hitPoints = other.getHit();
		_energyPoints = other.getEnergy();
		_attackDamage = other.getAttack();
	}
	std::cout << _name << " overload operator has been called." << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " destructor has been called." << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int ClapTrap::getHit() const
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergy() const
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttack() const
{
	return (this->_attackDamage);
}

void ClapTrap::setHit(int n)
{
	this->_hitPoints = n;
}
void ClapTrap::setEnergy(int n)
{
	this->_energyPoints = n;
}
void ClapTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
		this->setEnergy(this->getEnergy() - 1);
		return ;
	}
	else
		std::cout << "ClapTrap " << _name << " can't attack." << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	this->setHit(this->getHit() - amount);
	std::cout << "ClapTrap " << _name << " took " << amount << " points of damage." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		this->setHit(this->getHit() + amount);
		this->setEnergy(this->getEnergy() - 1);
		std::cout << "ClapTrap " << _name << " repairs by " << amount << " hit points " << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << "can't repair himself." << std::endl;
}