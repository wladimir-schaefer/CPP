#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap constructor was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other):
	_name(other._name),
	_hit_points(other._hit_points),
	_energy_points(other._energy_points),
	_attack_damage(other._attack_damage)
{
	std::cout << "ClapTrap copy constructor was called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	if (this != &other) {
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	std::cout << "ClapTrap assigment operator was called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor was called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (_energy_points <= 0 || _hit_points <= 0){
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points for attack." << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	_hit_points -= amount;
	std::cout << "ClapTrap " << _name << " lost " << amount
		<< " hit points!" << std::endl;
}

int ClapTrap::getHitPoints() const {
 return _hit_points;
}

int ClapTrap::getEnergyPoints() const {
	return _energy_points;
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

