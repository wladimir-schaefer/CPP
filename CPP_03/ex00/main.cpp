#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a = ClapTrap("foo");
	ClapTrap b = ClapTrap("bar");
	
	a.attack("bar");
	b.takeDamage(2);
	b.beRepaired(1);

	return 0;
}