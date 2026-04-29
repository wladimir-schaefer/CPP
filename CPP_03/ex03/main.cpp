#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main() {
	std::cout << "FragTrap Construction" << std::endl;
	{
		FragTrap a("Frag_A");
	}

	std::cout << "\nCopy Constructor" << std::endl;
	FragTrap b("Frag_B");
	FragTrap c(b);

	b.attack("enemy1");
	c.attack("enemy2");

	std::cout << "\nAssignment Operator" << std::endl;
	FragTrap d("Frag_D");
	d = b;
	d.attack("enemy3");

	std::cout << "\nSpecial Ability" << std::endl;
	d.highFivesGuys();
	std::cout << std::endl;
	return 0;
}