/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:22:10 by wschafer          #+#    #+#             */
/*   Updated: 2026/03/25 18:31:00 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::~Zombie ( void ){
	std::cout << "Zombie " << name << " destroyed\n";
}

void Zombie::announce( void ){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}