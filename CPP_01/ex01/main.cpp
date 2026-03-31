/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:27:13 by wschafer          #+#    #+#             */
/*   Updated: 2026/03/31 10:48:03 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){

	int N = 5;
	
	Zombie* horde = zombieHorde(N, "Zombie");

	for (int i = 0; i < N; i++) {
		std::cout << i << ": ";
		horde[i].announce();
	}

	delete[] horde;
}