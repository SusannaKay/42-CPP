/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:38:35 by skayed            #+#    #+#             */
/*   Updated: 2025/11/17 15:09:29 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie *horde = zombieHorde(n, "zombie ");

	for (int i = 0; i < n; i++)
	{
		horde[i].Announce();
	}
	delete[] horde;
	return (0);
}