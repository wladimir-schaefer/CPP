#include "Zombie.hpp"

Zombie* newZombie( std::string name ){

	Zombie *zombiePtr = new Zombie(name);
	return zombiePtr;
}
