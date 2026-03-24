/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:44:56 by wschafer          #+#    #+#             */
/*   Updated: 2026/03/24 19:20:29 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
	
	Zombie zombie;
	Zombie *zombie_p = &zombie;
	zombie.name = name;
	zombie.announce();
	return zombie_p;
}
