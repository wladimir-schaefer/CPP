#include "Zombie.hpp"

int	main(){

	randomChump("Foo");
	Zombie* z = newZombie("Bob");
	z->announce();
	delete z;
	return 0;
}