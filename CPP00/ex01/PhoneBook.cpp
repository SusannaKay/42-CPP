/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:56:23 by skayed            #+#    #+#             */
/*   Updated: 2025/11/10 11:50:14 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
}
PhoneBook::~PhoneBook()
{
}
static std::string trimContact( std::string str)
{
		
		if (str.length() > 10)
			str = str.substr(0,9) + ".";
	return str;
			
}

void PhoneBook::searchContact(void)
{
	int index;
	
	if (count == 0) {
        std::cout << "No contacts saved yet." << std::endl;
        return;
    }
	std::cout << "|"
				<< std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << std::right << "|";
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << trimContact(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << trimContact(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << trimContact(contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}
	std::cout << "Enter contact index: ";
	std::cin >> index;
	if (!std::cin)
	{
		std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid index.\n";
    return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if ((index > 0 && index < 9))
		displayContact(index - 1);
	else
		std::cout << "Invalid index" << std::endl;
	return;
	
}

static bool is_valid(const std::string& s, int digits_flag)
{
    bool only_spaces = true;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!isspace(static_cast<unsigned char>(s[i])))
        {
            only_spaces = false;
            break;
        }
    }
    if (s.empty() || only_spaces)
        return false;
    if (digits_flag == 1)
    {
        for (size_t i = 0; i < s.length(); i++)
        {
            if (!isdigit(static_cast<unsigned char>(s[i])))
                return false;
        }
    }

    return true;
}

static std::string ask_field(const std::string& type, int digits_flag)
{
    std::string str;

    while (true)
    {
        std::cout << "Enter " << type << ":" << std::endl;

        if (!std::getline(std::cin, str))
            return "EOF";

        if (is_valid(str, digits_flag))
            return str;

        if (digits_flag == 1)
            std::cout << "Field must contain only digits. Try again." << std::endl;
        else
            std::cout << "Field cannot be empty. Try again." << std::endl;
    }
}


void PhoneBook::addContact()
{
	std::string str;

	str = ask_field("First Name", 0);
	if (str == "EOF")
    	return;
	contacts[index].setFirstName(str);
	str = ask_field("Last Name",0);
	if (str == "EOF")
    	return;
	contacts[index].setLastName(str);
	str = ask_field("Nickname",0);
	if (str == "EOF")
    	return;
	contacts[index].setNickname(str);
	str = ask_field("Phone Number", 1);
	contacts[index].setPhoneNumber(str);
	str = ask_field("Darkest Secret",0);
	if (str == "EOF")
    	return;
	contacts[index].setDarkestSecret(str);
	index++;
	if (index == 8)
		index = 0;
	if (count < 8)
        count++;
}
void PhoneBook::displayContact(int index)
{
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
