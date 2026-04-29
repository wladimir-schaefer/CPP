#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): 
	ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
	std::cout << "DiamondTrap constructor was called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor was called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "DiamondTrap assignment operator was called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor was called" << std::endl;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "DiamondTrap name - " << _name << std::endl;
	std::cout << "ClapTrap name - " << ClapTrap::_name << std::endl;
}
