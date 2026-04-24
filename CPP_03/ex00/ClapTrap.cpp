#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Constructor was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other):
	_name(other._name),
	_hit_points(other._hit_points),
	_energy_points(other._energy_points),
	_attack_damage(other._attack_damage)
{
	std::cout << "Copy constructor was called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	if (this != &other) {
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor was called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	_energy_points--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	_hit_points -= amount;
	std::cout << "ClapTrap " << _name << " lost " << amount
		<< " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energy_points <= 0 || _hit_points <= 0) {
		std::cout << "ClapTrap " << _name << " cannot repair itself." << std::endl;
		return;
	}
	_energy_points--;
	_hit_points += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, it regains "
		<< amount << " hit points." << std::endl;
}

