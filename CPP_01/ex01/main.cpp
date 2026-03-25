/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:27:13 by wschafer          #+#    #+#             */
/*   Updated: 2026/03/25 22:49:46 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){

	int N = 5;
	
	Zombie* horde = zombieHorde(N, "Zombie");

	for (int i = 0; i < N; i++) {
		horde[i].announce();
	}

	delete[] horde;
}