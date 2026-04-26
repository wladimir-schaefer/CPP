#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap constructor was called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor was called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap assigment operator was called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor was called" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap is in Gate keeper mode" << std::endl;
}
