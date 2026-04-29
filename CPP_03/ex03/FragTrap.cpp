#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "FragTrap constructor was called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor was called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap assignment operator was called" << std::endl;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor was called" << std::endl;
}

void FragTrap::attack(const std::string& target){
	if (_energy_points <= 0 || _hit_points <= 0){
		std::cout << "FragTrap " << _name << " doesn't have enough energy points for attack." << std::endl;
		return;
	}
	_energy_points--;
	std::cout << "FragTrap " << _name << " attacks " << target
		<< ", causing " << _attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << _name << " high-fives" << std::endl;
}
