#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB ( void ){}

void HumanB::setWeapon(Weapon &weapon){
		this->weapon = &weapon;
}

void HumanB::attack(){
	if (weapon)
	{
		std::cout << name << " attacks with their " << weapon->getType()
			<< std::endl;
	}
}