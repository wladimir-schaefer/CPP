#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie( void ){}

Zombie::~Zombie ( void ){
	std::cout << "Zombie " << name << " destroyed\n";
}

void Zombie::announce( void ){
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name){
	this->name = name;
}