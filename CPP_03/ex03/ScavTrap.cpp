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

void ScavTrap::attack(const std::string& target){
	if (_energy_points <= 0 || _hit_points <= 0){
		std::cout << "ScavTrap " << _name << " doesn't have enough energy points for attack." << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap is in Gate keeper mode" << std::endl;
}
