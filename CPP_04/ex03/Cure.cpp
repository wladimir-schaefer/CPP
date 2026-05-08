#include "Cure.hpp"

Cure::Cure() {}
Cure::Cure(const Cure &other) {}
Cure &Cure::operator=(const Cure &other) {}
Cure::~Cure() {}

Cure Cure::clone() {
	return (new Cure)
}

void Cure::use(ICharacter&){
	std::cout << "* heals " << 
	ICharacter->getName() << "’s wounds *" << std::endl;
}