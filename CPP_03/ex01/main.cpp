#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	std::cout << "Test 1 - ClapTrap Copy Constructor" << std::endl;
	ClapTrap a("Clap_a");
	ClapTrap b(a);
	a.attack("target1");
	std::cout << "Energy points ClapTrap a = " << a.getEnergyPoints() << std::endl;
	std::cout << "Energy points ClapTrap b = " << b.getEnergyPoints() << std::endl;
	a.takeDamage(5);
	std::cout << "Hit points ClapTrap a = " << a.getHitPoints() << std::endl;
	std::cout << "Hit points ClapTrap b = " << b.getHitPoints() << std::endl;

	std::cout << "\nTest 2 - ClapTrap Assignment Constructor" << std::endl;
	ClapTrap c("Clap_c");
	c = a;
	c.attack("target3");
	std::cout << "Energy points ClapTrap c = " << c.getEnergyPoints() << std::endl;
	std::cout << "Hit points ClapTrap c = " << c.getHitPoints() << std::endl;

	std::cout << "\nTest 3 - ScavTrap Copy Constructor" << std::endl;
	ScavTrap d("Scav_d");
	ScavTrap e(d);
	d.attack("enemy1");
	std::cout << "Energy points ScavTrap d = " << d.getEnergyPoints() << std::endl;
	std::cout << "Energy points ScavTrap e = " << e.getEnergyPoints() << std::endl;
	d.takeDamage(5);
	std::cout << "Hit points ScavTrap d = " << d.getHitPoints() << std::endl;
	std::cout << "Hit points ScavTrap e = " << e.getHitPoints() << std::endl;

	std::cout << "\nTest 4 - ScavTrap Assignment Constructor" << std::endl;
	ScavTrap f("Scav_f");
	f = d;
	f.attack("enemy3");
	std::cout << "Energy points ScavTrap f = " << f.getEnergyPoints() << std::endl;
	std::cout << "Hit points ScavTrap f = " << f.getHitPoints() << std::endl;
	f.guardGate();

	return 0;
}