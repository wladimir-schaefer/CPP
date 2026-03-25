/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:27:13 by wschafer          #+#    #+#             */
/*   Updated: 2026/03/25 19:20:10 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(){

	randomChump("Foo");
	Zombie* z = newZombie("Bob");
	z->announce();
	delete z;
	return 0;
}