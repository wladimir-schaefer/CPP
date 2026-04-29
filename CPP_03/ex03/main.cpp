#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Construction ===" << std::endl;
	DiamondTrap a("Diamond_A");

	std::cout << "\n=== Copy Constructor ===" << std::endl;
	DiamondTrap b(a);

	std::cout << "\n=== Assignment ===" << std::endl;
	DiamondTrap c("Diamond_C");
	c = a;

	std::cout << "\n=== Actions ===" << std::endl;
	a.attack("enemy1");
	a.whoAmI();

	std::cout << "\n=== End of scope ===" << std::endl;
	return 0;
}	