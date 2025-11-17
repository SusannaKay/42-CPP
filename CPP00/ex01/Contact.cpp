/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:56:16 by skayed            #+#    #+#             */
/*   Updated: 2025/11/10 11:44:42 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string str)
{
	firstName = str;
}

void Contact::setLastName(std::string str)
{
	lastName = str;
}

void Contact::setNickname(std::string str)
{
	nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
	secret = str;
}

std::string Contact::getFirstName()
{
	return (firstName);
}
std::string Contact::getLastName()
{
	return (lastName);
}
std::string Contact::getNickname()
{
	return (nickname);
}
std::string Contact::getPhoneNumber()
{
	return (phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return (secret);
}
